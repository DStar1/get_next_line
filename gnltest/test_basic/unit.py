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
				"test_*.c",
				"test1.in"
				]
		self.ucopy(srcfiles, cd=True)

		nolib = 0
		if not os.path.isdir("./libft"):
			self.trace("No libft found")
			nolib = 1

		if nolib == 0:
			if not self.execute("make -C libft/ fclean && make -C libft/", "compil_userlib_output", required_files=srcfiles, trace_output=True, trace_cmd=False, copyback_files=["libft"], maxtime=30):
				self.comment("KO (Does not compile)")

		self.rcopy(corrfiles)

		self.execute("grep -c \"^# *define BUFF_SIZE[\t ]*[0-9]*$\" get_next_line.h", "grep_output", required_files=corrfiles + srcfiles, trace_output=False, trace_cmd=False)

		with open("grep_output", "r") as fp:
			output = fp.read()

		if (output == "1\n"):
			self.trace("Define found")
		else:
			self.comment("KO (Define not found or multiple define)")
			self.trace("KO (Define not found or multiple define)")
			self.ko()
			return

		############################# BUFF_SIZE 1 #############################
		if self.execute("sed -i -- \"s/^# *define BUFF_SIZE[\t ]*[0-9]*$/# define BUFF_SIZE 1/g\" get_next_line.h", "sed_output", required_files=corrfiles + srcfiles, copyback_files=["get_next_line.h"], trace_output=True, trace_cmd=False):
			self.trace("BUFF_SIZE changed to 1")

		if nolib == 1:
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_simple.o -c test_simple.c && clang -Wall -Werror -Wextra -o test_fds.o -c test_fds.c && clang -o test_gnl test_simple.o test_fds.o main.o get_next_line.o", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make fclean && make test_gnl", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return

		self.execute("ulimit -n 2048 && ./test_gnl", "test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z_0-9]+: \[ok\]')

		count = 0
		for line in lines:
			if reg.match(line):
				count += 1

		############################# BUFF_SIZE 4 #############################
		if self.execute("sed -i -- \"s/^# *define BUFF_SIZE[\t ]*[0-9]*$/# define BUFF_SIZE 4/g\" get_next_line.h", "sed_output", required_files=corrfiles + srcfiles, copyback_files=["get_next_line.h"], trace_output=True, trace_cmd=False):
			self.trace("BUFF_SIZE changed to 4")
		if nolib == 1:
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_simple.o -c test_simple.c && clang -Wall -Werror -Wextra -o test_fds.o -c test_fds.c && clang -o test_gnl test_simple.o test_fds.o main.o get_next_line.o", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make fclean && make test_gnl", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return

		self.execute("ulimit -n 2048 && ./test_gnl", "test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z_0-9]+: \[ok\]')

		for line in lines:
			if reg.match(line):
				count += 1

		############################ BUFF_SIZE 100 ############################
		if self.execute("sed -i -- \"s/^# *define BUFF_SIZE[\t ]*[0-9]*$/# define BUFF_SIZE 100/g\" get_next_line.h", "sed_output", required_files=corrfiles + srcfiles, copyback_files=["get_next_line.h"], trace_output=True, trace_cmd=False):
			self.trace("BUFF_SIZE changed to 100")
		if nolib == 1:
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_simple.o -c test_simple.c && clang -Wall -Werror -Wextra -o test_fds.o -c test_fds.c && clang -o test_gnl test_simple.o test_fds.o main.o get_next_line.o", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make fclean && make test_gnl", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return

		self.execute("ulimit -n 2048 && ./test_gnl", "test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z_0-9]+: \[ok\]')

		for line in lines:
			if reg.match(line):
				count += 1

		############################ BUFF_SIZE 2056 ############################
		if self.execute("sed -i -- \"s/^# *define BUFF_SIZE[\t ]*[0-9]*$/# define BUFF_SIZE 2056/g\" get_next_line.h", "sed_output", required_files=corrfiles + srcfiles, copyback_files=["get_next_line.h"], trace_output=True, trace_cmd=False):
			self.trace("BUFF_SIZE changed to 2056")
		if nolib == 1:
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_simple.o -c test_simple.c && clang -Wall -Werror -Wextra -o test_fds.o -c test_fds.c && clang -o test_gnl test_simple.o test_fds.o main.o get_next_line.o", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make fclean && make test_gnl", "compil_test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return

		self.execute("ulimit -n 2048 && ./test_gnl", "test_output", required_files=corrfiles + srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z_0-9]+: \[ok\]')

		for line in lines:
			if reg.match(line):
				count += 1

		self.trace("%d/%d correct tests" % (count, 8))
		self.comment("%d/%d correct test" % (count, 8))
		self.set_grade(count * 40 / 8)
		if count != 8:
			self.ko()
