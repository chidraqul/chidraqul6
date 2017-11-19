#made by ChillerDragon
#all rights reserved to ChillerDragon copyright(c) blabla

import sys
import os
import os.path

def cls():
	os.system('cls' if os.name=='nt' else 'clear')

def menu():
	cls()
	print("=======================================")
	print("ChillerDragon's Batch formater")
	print("print batch code with batch")
	print("create batch files with batch files")
	print("=======================================")
	print("enter the file to be formated (without file extesion)")
	global in_file
	global out_file
	in_file = raw_input("_")
	out_file = in_file + "_format.txt"
	in_file = in_file + ".bat"
	if not os.path.isfile(in_file):
		raw_input("File >" + in_file + "< not found.")
		#sys.exit()
		menu()
	if os.path.isfile(out_file):
		raw_input("File >" + out_file + "< already exists and can't be overwritten.")
		#sys.exit()
		menu()
	main_format()

def main_format():
	writeFile = open(out_file, "w");
	with open(in_file, "r") as ins:
		for line in ins:
			if not line.startswith("::") and not len(line) == 1 and not "test_cmd" in line:
				suffixLine = "echo " + line;
				escLine0 = suffixLine.replace("^","^^");
				escLine1 = escLine0.replace("(","^(");
				escLine2 = escLine1.replace(")","^)");
				escLine3 = escLine2.replace("<","^<");
				escLine4 = escLine3.replace(">","^>");
				escLine5 = escLine4.replace("%","%%");
				writeFile.write(escLine5);
	writeFile.close();
	print("Succsessfully formated and saved to >" + out_file + "<")
	raw_input("press any key to format something else")
	menu()
	
menu()