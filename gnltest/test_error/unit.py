# -*- coding: utf-8 -*-

import re
import os

from deepthought.correction.units.c import CUnit

#Ce script est franchement tiré de l'ancien car j'ai pas la foi de bidouiller les fichiers de correction dans tous les sens
#pour les rendre parfaitement compatible. A faire une autre fois.

class Unit(CUnit):
	def run(self):
		srcfiles = [
				"libft",
				"get_next_line.c",
				"get_next_line.h"
				]
		corrfiles = [
				"Makefile",
				"main.c",
				"tests.h",
				"test_*.c"
				]
		self.ucopy(srcfiles, cd=True)

		nolib = 0
		if not os.path.isdir("./libft"):
			self.trace("No libft found")
			nolib = 1

		if nolib == 0:
			if not self.execute("make -C libft/ fclean && make -C libft/", "compil_userlib_output", required_files=srcfiles, trace_output=True, trace_cmd=False, copyback_files=["libft"], maxtime=30):
				self.trace("KO (Libft does not compile)")

		self.rcopy(corrfiles)
		if nolib == 1:
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_errors.o -c test_errors.c && clang -o test_gnl test_errors.o main.o get_next_line.o", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make test_gnl", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return

		self.execute("./test_gnl", "test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z]+: \[ok\]')

		count = 0
		for line in lines:
			if reg.match(line):
				count += 1
		self.trace("%d/%d correct tests" % (count, 1))
		self.comment("%d/%d correct tests" % (count, 1))
		self.set_grade(count * 10 / 1)

		if count != 1:
			self.ko()
