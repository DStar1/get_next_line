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
		corrfiles = []
		self.ucopy(srcfiles, cd=True)
		self.rcopy(corrfiles)

		count = 0

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

		self.execute("grep -c \"\t\{1,\}static[\t ]\{1,\}[a-z_]\{3,\}[\t ]\{1,\}.\{1,\};\" get_next_line.c", "grep_output", required_files=corrfiles + srcfiles, trace_output=False, trace_cmd=False)

		with open("grep_output", "r") as fp:
			output = fp.read()

		if (output == "1\n"):
			self.trace("OK 1 static found")
			count += 1
		else:
			self.trace("KO (Multiple static)")

		self.trace("%d/%d correct tests" % (count, 1))
		self.comment("%d/%d correct test" % (count, 1))
		self.set_grade(count * 10 / 1)
		if count != 1:
			self.ko()
