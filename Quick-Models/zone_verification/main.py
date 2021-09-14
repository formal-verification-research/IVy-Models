import os
import time
# import pygame
# from pygame import mixer

def check_pass(file_name):
	with open(file_name, 'r') as read_obj:
		for line in read_obj:
			if "PASS" in line:
				return True
	return False

def check_dropped(file_name):
	with open(file_name, 'r') as read_obj:
		for line in read_obj:
			if "flit.dropped = true" in line:
				return True
	return False

def check_failed(file_name):
	with open(file_name, 'r') as read_obj:
		for line in read_obj:
			if "error:" in line:
				play_beep()
				for x in range(0,10):
					print("\033[0;30;41mIVY RETURNED ERROR\033[0m")
				play_beep()
				return True
	return False

def play_beep():
	from sys import platform
	if platform == "win32" or platform == "win64":
		import winsound
		duration = 1000  # milliseconds
		freq = 500  # Hz
		winsound.Beep(freq, duration)
	else:
		print("\a")

play_beep()
print("\033[0;30;42mLet's do this thing.\033[0m\n")

print("Your file options are as follows:")
os.system("ls *.ivy")
print("")

filename = input("\033[0;30;43mInput the name of the file without the extension: \033[0;37;44m")
droptest = input("\033[0;30;43mWould you like dropped flit testing? y/n \033[0;37;44m")
if filename.endswith == ".ivy":
	filename = input("\033[0;30;41mWARNING! Try again without using .ivy: \033[0;37;44m")
ts = str(int(time.time()))
foldername = filename + "_" + droptest + "_tests_" + ts

drop_tester = False

if droptest == "y" or droptest == "Y":
	drop_tester = True

os.system("mkdir " + foldername)

if drop_tester:
	os.system("cp -i " + filename + ".ivy " + foldername + "/0.ivy")
	dropCount = 0
else:
	with open(filename + ".ivy", 'r') as old:
		with open(foldername + "/0.ivy", 'w') as new:
			for line in old:
				if "invariant (~flit.dropped)" in line:
					break
				else:
					new.write(line)



logfile = open(foldername + "/log.txt", 'a')

print("\033[0m\nAll files opened correctly. Expect a large number of beeps once the script is finished.")
print("Look in this folder once completed: \033[0;36;40m" + foldername + "\033[0m")
if drop_tester:
	print("\033[0;33;40mThis program will take a long time to run (better protocol = faster runtime)\033[0m")
print("The program will continue running without further interaction. Hold \033[0;30;43mCTRL+C\033[0m to exit.\n")

index = 0
finished = False

while not(finished): # and index < 200:
	
	general_timer_start = time.time()

	zn6 = 'x'
	zn5 = 'x'
	zn4 = 'x'
	zn3 = 'x'
	zn2 = 'x'
	zn1 = 'x'
	zn0 = 'x'
	trav6 = 'new'
	trav5 = 'new'
	trav4 = 'new'
	trav3 = 'new'
	trav2 = 'new'
	trav1 = 'new'
	trav0 = 'new'
	nl  = 'default'
	el  = 'default'
	sl  = 'default'
	wl  = 'default'
	nl1 = 'default'
	el1 = 'default'
	sl1 = 'default'
	wl1 = 'default'
	nl2 = 'default'
	el2 = 'default'
	sl2 = 'default'
	wl2 = 'default'
	nl3 = 'default'
	el3 = 'default'
	sl3 = 'default'
	wl3 = 'default'
	nl4 = 'default'
	el4 = 'default'
	sl4 = 'default'
	wl4 = 'default'
	nl5 = 'default'
	el5 = 'default'
	sl5 = 'default'
	wl5 = 'default'
	nl6 = 'default'
	el6 = 'default'
	sl6 = 'default'
	wl6 = 'default'

	dropped = False

	new_invariant = ""
	ivy_timer_start = time.time()
	os.system("ivy_check mc=true trace=true " + foldername + "/" + str(index) + ".ivy > " + foldername + "/" + str(index) + ".txt")
	ivy_timer_duration = time.time() - ivy_timer_start

	tempfilename = foldername + "/" + str(index) + ".txt"

	if check_failed(tempfilename):
		print("\033[0;30;41mFAILURE: IVY ERROR!!! Big oops.\033[0m")
		exit()
	elif check_pass(tempfilename):
		print("Testing has completed.")
		if index == 0:
			print("\033[0;30;42mNO LIVELOCKS OR DROPS FOUND! HIP HIP HOORAY!\033[0m")
		finished = True
		break
	elif check_dropped(tempfilename) and drop_tester:
		dropped = True
		with open(tempfilename, 'r') as read_obj:
			waiting = True
			for line in read_obj:
				if waiting:
					if "call ext:flit.moveFlit" in line:
						waiting = False
						continue
				elif "easyTrace.traveling6 = " in line:
					*temp, trav6 = line.split()
					print("@trav6 = " + trav6 + ".")
				elif "easyTrace.traveling5 = " in line:
					*temp, trav5 = line.split()
					print("@trav5 = " + trav5 + ".")
				elif "easyTrace.traveling4 = " in line:
					*temp, trav4 = line.split()
					print("@trav4 = " + trav4 + ".")
				elif "easyTrace.traveling3 = " in line:
					*temp, trav3 = line.split()
					print("@trav3 = " + trav3 + ".")
				elif "easyTrace.traveling2 = " in line:
					*temp, trav2 = line.split()
					print("@trav2 = " + trav2 + ".")
				elif "easyTrace.traveling1 = " in line:
					*temp, trav1 = line.split()
					print("@trav1 = " + trav1 + ".")
				elif "easyTrace.traveling0 = " in line:
					*temp, trav0 = line.split()
					print("@trav0 = " + trav0 + ".")
				elif "easyTrace.toZone6 = " in line:
					*temp, zn6 = line.split()
					print("@zn6 = " + zn6 + ".")
				elif "easyTrace.toZone5 = " in line:
					*temp, zn5 = line.split()
					print("@zn5 = " + zn5 + ".")
				elif "easyTrace.toZone4 = " in line:
					*temp, zn4 = line.split()
					print("@zn4 = " + zn4 + ".")
				elif "easyTrace.toZone3 = " in line:
					*temp, zn3 = line.split()
					print("@zn3 = " + zn3 + ".")
				elif "easyTrace.toZone2 = " in line:
					*temp, zn2 = line.split()
					print("@zn2 = " + zn2 + ".")
				elif "easyTrace.toZone1 = " in line:
					*temp, zn1 = line.split()
					print("@zn1 = " + zn1 + ".")
				elif "easyTrace.toZone0 = " in line:
					*temp, zn0 = line.split()
					print("@zn0 = " + zn0 + ".")
				elif "easyTrace.northLink = " in line: #
					*temp, nl = line.split()
				elif "easyTrace.eastLink = " in line:
					*temp, el = line.split()
				elif "easyTrace.westLink = " in line:
					*temp, wl = line.split()
				elif "easyTrace.southLink = " in line:
					*temp, sl = line.split()
				elif "easyTrace.northLink1 = " in line: #
					*temp, nl1 = line.split()
				elif "easyTrace.eastLink1 = " in line:
					*temp, el1 = line.split()
				elif "easyTrace.westLink1 = " in line:
					*temp, wl1 = line.split()
				elif "easyTrace.southLink1 = " in line:
					*temp, sl1 = line.split()
				elif "easyTrace.northLink2 = " in line: #
					*temp, nl2 = line.split()
				elif "easyTrace.eastLink2 = " in line:
					*temp, el2 = line.split()
				elif "easyTrace.westLink2 = " in line:
					*temp, wl2 = line.split()
				elif "easyTrace.southLink2 = " in line:
					*temp, sl2 = line.split()
				elif "easyTrace.northLink3 = " in line: #
					*temp, nl3 = line.split()
				elif "easyTrace.eastLink3 = " in line:
					*temp, el3 = line.split()
				elif "easyTrace.westLink3 = " in line:
					*temp, wl3 = line.split()
				elif "easyTrace.southLink3 = " in line:
					*temp, sl3 = line.split()
				elif "easyTrace.northLink4 = " in line: #
					*temp, nl4 = line.split()
				elif "easyTrace.eastLink4 = " in line:
					*temp, el4 = line.split()
				elif "easyTrace.westLink4 = " in line:
					*temp, wl4 = line.split()
				elif "easyTrace.southLink4 = " in line:
					*temp, sl4 = line.split()
				elif "easyTrace.northLink5 = " in line: #
					*temp, nl5 = line.split()
				elif "easyTrace.eastLink5 = " in line:
					*temp, el5 = line.split()
				elif "easyTrace.westLink5 = " in line:
					*temp, wl5 = line.split()
				elif "easyTrace.southLink5 = " in line:
					*temp, sl5 = line.split()
				elif "easyTrace.northLink6 = " in line: #
					*temp, nl6 = line.split()
				elif "easyTrace.eastLink6 = " in line:
					*temp, el6 = line.split()
				elif "easyTrace.westLink6 = " in line:
					*temp, wl6 = line.split()
				elif "easyTrace.southLink6 = " in line:
					*temp, sl6 = line.split()
		# new_invariant = " | (flit.zn6 = " + zn6 + " & flit.zn5 = " + zn5 + " & flit.zn4 = " + zn4 + " & flit.zn3 = " + zn3 + " & flit.zn2 = " + zn2 + " & flit.zn1 = " + zn1 + " & node.northLink = " + nl + " & node.eastLink = " + el + " & node.southLink = " + sl + " & node.westLink = " + wl + " & node.northLink1 = " + nl1 + " & node.eastLink1 = " + el1 + " & node.southLink1 = " + sl1 + " & node.westLink1 = " + wl1 + " & node.northLink2 = " + nl2 + " & node.eastLink2 = " + el2 + " & node.southLink2 = " + sl2 + " & node.westLink2 = " + wl2 + " & node.northLink3 = " + nl3 + " & node.eastLink3 = " + el3 + " & node.southLink3 = " + sl3 + " & node.westLink3 = " + wl3 + " & node.northLink4 = " + nl4 + " & node.eastLink4 = " + el4 + " & node.southLink4 = " + sl4 + " & node.westLink4 = " + wl4 + " & node.northLink5 = " + nl5 + " & node.eastLink5 = " + el5 + " & node.southLink5 = " + sl5 + " & node.westLink5 = " + wl5 + " & node.northLink6 = " + nl6 + " & node.eastLink6 = " + el6 + " & node.southLink6 = " + sl6 + " & node.westLink6 = " + wl6 + ")"
		new_invariant = " | ("
		if zn6 != "x":
			if new_invariant == " | (":
				new_invariant += "flit.zn6 = " + zn6
			else:
				new_invariant += " & flit.zn6 = " + zn6
		if zn5 != "x":
			if new_invariant == " | (":
				new_invariant += "flit.zn5 = " + zn5
			else:
				new_invariant += " & flit.zn5 = " + zn5
		if zn4 != "x":
			if new_invariant == " | (":
				new_invariant += "flit.zn4 = " + zn4
			else:
				new_invariant += " & flit.zn4 = " + zn4
		if zn3 != "x":
			if new_invariant == " | (":
				new_invariant += "flit.zn3 = " + zn3
			else:
				new_invariant += " & flit.zn3 = " + zn3
		if zn2 != "x":
			if new_invariant == " | (":
				new_invariant += "flit.zn2 = " + zn2
			else:
				new_invariant += " & flit.zn2 = " + zn2
		if new_invariant == " | (":
			new_invariant += "flit.zn1 = " + zn1
		else:
			new_invariant += " & flit.zn1 = " + zn1
		if trav6 != "new":
			new_invariant += " & flit.sent6 = " + trav6
		if trav5 != "new":
			new_invariant += " & flit.sent5 = " + trav5
		if trav4 != "new":
			new_invariant += " & flit.sent4 = " + trav4
		if trav3 != "new":
			new_invariant += " & flit.sent3 = " + trav3
		if trav2 != "new":
			new_invariant += " & flit.sent2 = " + trav2
		if trav1 != "new":
			new_invariant += " & flit.sent1 = " + trav1
		if nl6 != "default" and nl6 != "free":
			new_invariant += " & node.northLink6 = " + nl6
		if el6 != "default" and el6 != "free":
			new_invariant += " & node.eastLink6 = " + el6
		if sl6 != "default" and sl6 != "free":
			new_invariant += " & node.southLink6 = " + sl6
		if wl6 != "default" and nl6 != "free":
			new_invariant += " & node.westLink6 = " + wl6
		if nl5 != "default" and nl5 != "free":
			new_invariant += " & node.northLink5 = " + nl5
		if el5 != "default" and el5 != "free":
			new_invariant += " & node.eastLink5 = " + el5
		if sl5 != "default" and sl5 != "free":
			new_invariant += " & node.southLink5 = " + sl5
		if wl5 != "default" and wl5 != "free":
			new_invariant += " & node.westLink5 = " + wl5
		if nl4 != "default" and nl4 != "free":
			new_invariant += " & node.northLink4 = " + nl4
		if el4 != "default" and el4 != "free":
			new_invariant += " & node.eastLink4 = " + el4
		if sl4 != "default" and sl4 != "free":
			new_invariant += " & node.southLink4 = " + sl4
		if wl4 != "default" and wl4 != "free":
			new_invariant += " & node.westLink4 = " + wl4
		if nl3 != "default" and nl3 != "free":
			new_invariant += " & node.northLink3 = " + nl3
		if el3 != "default" and el3 != "free":
			new_invariant += " & node.eastLink3 = " + el3
		if sl3 != "default" and sl3 != "free":
			new_invariant += " & node.southLink3 = " + sl3
		if wl3 != "default" and wl3 != "free":
			new_invariant += " & node.westLink3 = " + wl3
		if nl2 != "default" and nl2 != "free":
			new_invariant += " & node.northLink2 = " + nl2
		if el2 != "default" and el2 != "free":
			new_invariant += " & node.eastLink2 = " + el2
		if sl2 != "default" and sl2 != "free":
			new_invariant += " & node.southLink2 = " + sl2
		if wl2 != "default" and wl2 != "free":
			new_invariant += " & node.westLink2 = " + wl2
		if nl1 != "default" and nl1 != "free":
			new_invariant += " & node.northLink1 = " + nl1
		if el1 != "default" and el1 != "free":
			new_invariant += " & node.eastLink1 = " + el1
		if sl1 != "default" and sl1 != "free":
			new_invariant += " & node.southLink1 = " + sl1
		if wl1 != "default" and wl1 != "free":
			new_invariant += " & node.westLink1 = " + wl1
		if nl != "default" and nl != "free":
			new_invariant += " & node.northLink = " + nl
		if el != "default" and el != "free":
			new_invariant += " & node.eastLink = " + el
		if sl != "default" and sl != "free":
			new_invariant += " & node.southLink = " + sl
		if wl != "default" and wl != "free":
			new_invariant += " & node.westLink = " + wl
		new_invariant += ")"

		# new_invariant = " | (flit.zn6 = " + zn6 + " & flit.zn5 = " + zn5 + " & flit.zn4 = " + zn4 + " & flit.zn3 = " + zn3 + " & flit.zn2 = " + zn2 + " & flit.zn1 = " + zn1 + " & flit.zn0 = " + zn0 + " & node.northLink = " + nl + " & node.eastLink = " + el + " & node.southLink = " + sl + " & node.westLink = " + wl + " & node.northLink1 = " + nl1 + " & node.eastLink1 = " + el1 + " & node.southLink1 = " + sl1 + " & node.westLink1 = " + wl1 + " & node.northLink2 = " + nl2 + " & node.eastLink2 = " + el2 + " & node.southLink2 = " + sl2 + " & node.westLink2 = " + wl2 + " & node.northLink3 = " + nl3 + " & node.eastLink3 = " + el3 + " & node.southLink3 = " + sl3 + " & node.westLink3 = " + wl3 + " & node.northLink4 = " + nl4 + " & node.eastLink4 = " + el4 + " & node.southLink4 = " + sl4 + " & node.westLink4 = " + wl4 + " & node.northLink5 = " + nl5 + " & node.eastLink5 = " + el5 + " & node.southLink5 = " + sl5 + " & node.westLink5 = " + wl5 + " & node.northLink6 = " + nl6 + " & node.eastLink6 = " + el6 + " & node.southLink6 = " + sl6 + " & node.westLink6 = " + wl6 + ")"
	else:
		with open(tempfilename, 'r') as read_obj:
			waiting = True
			for line in read_obj:
				if waiting:
					if "call ext:flit.moveFlit" in line:
						waiting = False
						continue
				elif "easyTrace.traveling6 = " in line:
					*temp, trav6 = line.split()
					print("trav6 = " + trav6 + ".")
				elif "easyTrace.traveling5 = " in line:
					*temp, trav5 = line.split()
					print("trav5 = " + trav5 + ".")
				elif "easyTrace.traveling4 = " in line:
					*temp, trav4 = line.split()
					print("trav4 = " + trav4 + ".")
				elif "easyTrace.traveling3 = " in line:
					*temp, trav3 = line.split()
					print("trav3 = " + trav3 + ".")
				elif "easyTrace.traveling2 = " in line:
					*temp, trav2 = line.split()
					print("trav2 = " + trav2 + ".")
				elif "easyTrace.traveling1 = " in line:
					*temp, trav1 = line.split()
					print("trav1 = " + trav1 + ".")
				elif "easyTrace.traveling0 = " in line:
					*temp, trav0 = line.split()
					print("trav0 = " + trav0 + ".")
				elif "easyTrace.toZone6 = " in line:
					*temp, zn6 = line.split()
					print("zn6 = " + zn6 + ".")
				elif "easyTrace.toZone5 = " in line:
					*temp, zn5 = line.split()
					print("zn5 = " + zn5 + ".")
				elif "easyTrace.toZone4 = " in line:
					*temp, zn4 = line.split()
					print("zn4 = " + zn4 + ".")
				elif "easyTrace.toZone3 = " in line:
					*temp, zn3 = line.split()
					print("zn3 = " + zn3 + ".")
				elif "easyTrace.toZone2 = " in line:
					*temp, zn2 = line.split()
					print("zn2 = " + zn2 + ".")
				elif "easyTrace.toZone1 = " in line:
					*temp, zn1 = line.split()
					print("zn1 = " + zn1 + ".")
				elif "easyTrace.toZone0 = " in line:
					*temp, zn0 = line.split()
					print("zn0 = " + zn0 + ".")
				elif "easyTrace.northLink = " in line: #
					*temp, nl = line.split()
				elif "easyTrace.eastLink = " in line:
					*temp, el = line.split()
				elif "easyTrace.westLink = " in line:
					*temp, wl = line.split()
				elif "easyTrace.southLink = " in line:
					*temp, sl = line.split()
				elif "easyTrace.northLink1 = " in line: #
					*temp, nl1 = line.split()
				elif "easyTrace.eastLink1 = " in line:
					*temp, el1 = line.split()
				elif "easyTrace.westLink1 = " in line:
					*temp, wl1 = line.split()
				elif "easyTrace.southLink1 = " in line:
					*temp, sl1 = line.split()
				elif "easyTrace.northLink2 = " in line: #
					*temp, nl2 = line.split()
				elif "easyTrace.eastLink2 = " in line:
					*temp, el2 = line.split()
				elif "easyTrace.westLink2 = " in line:
					*temp, wl2 = line.split()
				elif "easyTrace.southLink2 = " in line:
					*temp, sl2 = line.split()
				elif "easyTrace.northLink3 = " in line: #
					*temp, nl3 = line.split()
				elif "easyTrace.eastLink3 = " in line:
					*temp, el3 = line.split()
				elif "easyTrace.westLink3 = " in line:
					*temp, wl3 = line.split()
				elif "easyTrace.southLink3 = " in line:
					*temp, sl3 = line.split()
				elif "easyTrace.northLink4 = " in line: #
					*temp, nl4 = line.split()
				elif "easyTrace.eastLink4 = " in line:
					*temp, el4 = line.split()
				elif "easyTrace.westLink4 = " in line:
					*temp, wl4 = line.split()
				elif "easyTrace.southLink4 = " in line:
					*temp, sl4 = line.split()
				elif "easyTrace.northLink5 = " in line: #
					*temp, nl5 = line.split()
				elif "easyTrace.eastLink5 = " in line:
					*temp, el5 = line.split()
				elif "easyTrace.westLink5 = " in line:
					*temp, wl5 = line.split()
				elif "easyTrace.southLink5 = " in line:
					*temp, sl5 = line.split()
				elif "easyTrace.northLink6 = " in line: #
					*temp, nl6 = line.split()
				elif "easyTrace.eastLink6 = " in line:
					*temp, el6 = line.split()
				elif "easyTrace.westLink6 = " in line:
					*temp, wl6 = line.split()
				elif "easyTrace.southLink6 = " in line:
					*temp, sl6 = line.split()
		new_invariant = " | (flit.zn6 = " + zn6 + " & flit.zn5 = " + zn5 + " & flit.zn4 = " + zn4 + " & flit.zn3 = " + zn3 + " & flit.zn2 = " + zn2 + " & flit.zn1 = " + zn1 
		# new_invariant = " | ("
		if nl6 != "default" and nl6 != "free":
			new_invariant += " & node.northLink6 = " + nl6
		if el6 != "default" and el6 != "free":
			new_invariant += " & node.eastLink6 = " + el6
		if sl6 != "default" and sl6 != "free":
			new_invariant += " & node.southLink6 = " + sl6
		if wl6 != "default" and nl6 != "free":
			new_invariant += " & node.westLink6 = " + wl6
		if nl5 != "default" and nl5 != "free":
			new_invariant += " & node.northLink5 = " + nl5
		if el5 != "default" and el5 != "free":
			new_invariant += " & node.eastLink5 = " + el5
		if sl5 != "default" and sl5 != "free":
			new_invariant += " & node.southLink5 = " + sl5
		if wl5 != "default" and wl5 != "free":
			new_invariant += " & node.westLink5 = " + wl5
		if nl4 != "default" and nl4 != "free":
			new_invariant += " & node.northLink4 = " + nl4
		if el4 != "default" and el4 != "free":
			new_invariant += " & node.eastLink4 = " + el4
		if sl4 != "default" and sl4 != "free":
			new_invariant += " & node.southLink4 = " + sl4
		if wl4 != "default" and wl4 != "free":
			new_invariant += " & node.westLink4 = " + wl4
		if nl3 != "default" and nl3 != "free":
			new_invariant += " & node.northLink3 = " + nl3
		if el3 != "default" and el3 != "free":
			new_invariant += " & node.eastLink3 = " + el3
		if sl3 != "default" and sl3 != "free":
			new_invariant += " & node.southLink3 = " + sl3
		if wl3 != "default" and wl3 != "free":
			new_invariant += " & node.westLink3 = " + wl3
		if nl2 != "default" and nl2 != "free":
			new_invariant += " & node.northLink2 = " + nl2
		if el2 != "default" and el2 != "free":
			new_invariant += " & node.eastLink2 = " + el2
		if sl2 != "default" and sl2 != "free":
			new_invariant += " & node.southLink2 = " + sl2
		if wl2 != "default" and wl2 != "free":
			new_invariant += " & node.westLink2 = " + wl2
		if nl1 != "default" and nl1 != "free":
			new_invariant += " & node.northLink1 = " + nl1
		if el1 != "default" and el1 != "free":
			new_invariant += " & node.eastLink1 = " + el1
		if sl1 != "default" and sl1 != "free":
			new_invariant += " & node.southLink1 = " + sl1
		if wl1 != "default" and wl1 != "free":
			new_invariant += " & node.westLink1 = " + wl1
		if nl != "default" and nl != "free":
			new_invariant += " & node.northLink = " + nl
		if el != "default" and el != "free":
			new_invariant += " & node.eastLink = " + el
		if sl != "default" and sl != "free":
			new_invariant += " & node.southLink = " + sl
		if wl != "default" and wl != "free":
			new_invariant += " & node.westLink = " + wl
		new_invariant += ")"
	

	inv1 = "invariant ~(flit.sent6 = south & flit.sent5 = west & flit.sent4 = north & flit.sent3 = east & flit.sent2 = south & flit.sent1 = west & flit.sent0 = north)"
	inv2 = "invariant ~(flit.sent6 = west & flit.sent5 = north & flit.sent4 = east & flit.sent3 = south & flit.sent2 = west & flit.sent1 = north & flit.sent0 = east)"
	inv3 = "invariant ~(flit.sent6 = north & flit.sent5 = east & flit.sent4 = south & flit.sent3 = west & flit.sent2 = north & flit.sent1 = east & flit.sent0 = south)"
	inv4 = "invariant ~(flit.sent6 = east & flit.sent5 = south & flit.sent4 = west & flit.sent3 = north & flit.sent2 = east & flit.sent1 = south & flit.sent0 = west)"
	inv5 = "invariant ~(flit.sent6 = east & flit.sent5 = north & flit.sent4 = west & flit.sent3 = south & flit.sent2 = east & flit.sent1 = north & flit.sent0 = west)"
	inv6 = "invariant ~(flit.sent6 = north & flit.sent5 = west & flit.sent4 = south & flit.sent3 = east & flit.sent2 = north & flit.sent1 = west & flit.sent0 = south)"
	inv7 = "invariant ~(flit.sent6 = west & flit.sent5 = south & flit.sent4 = east & flit.sent3 = north & flit.sent2 = west & flit.sent1 = south & flit.sent0 = east)"
	inv8 = "invariant ~(flit.sent6 = south & flit.sent5 = east & flit.sent4 = north & flit.sent3 = west & flit.sent2 = south & flit.sent1 = east & flit.sent0 = north)"
	inv9 = "invariant ~(flit.sent6 = west & flit.sent5 = east & flit.sent4 = west & flit.sent3 = east & flit.sent2 = west & flit.sent1 = east & flit.sent0 = west)"
	inv10 = "invariant ~(flit.sent6 = east & flit.sent5 = west & flit.sent4 = east & flit.sent3 = west & flit.sent2 = east & flit.sent1 = west & flit.sent0 = east)"
	inv11 = "invariant ~(flit.sent6 = north & flit.sent5 = south & flit.sent4 = north & flit.sent3 = south & flit.sent2 = north & flit.sent1 = south & flit.sent0 = north)"
	inv12 = "invariant ~(flit.sent6 = south & flit.sent5 = north & flit.sent4 = south & flit.sent3 = north & flit.sent2 = south & flit.sent1 = north & flit.sent0 = south)"
	inv13 = "invariant (~flit.dropped)"
	# inv13b = "(~flit.dropped) | ~(node.northLink = free | node.eastLink = free | node.southLink = free | node.westLink = free)"

	with open(foldername + "/" + str(index) + ".ivy", 'r') as read_obj:
		waiting = True
		for line in read_obj:
			if inv1 in line:
				inv1 = line.rstrip("\n")
			if inv2 in line:
				inv2 = line.rstrip("\n")
			elif inv3 in line:
				inv3 = line.rstrip("\n")
			elif inv4 in line:
				inv4 = line.rstrip("\n")
			elif inv5 in line:
				inv5 = line.rstrip("\n")
			elif inv6 in line:
				inv6 = line.rstrip("\n")
			elif inv7 in line:
				inv7 = line.rstrip("\n")
			elif inv8 in line:
				inv8 = line.rstrip("\n")
			elif inv9 in line:
				inv9 = line.rstrip("\n")
			elif inv10 in line:
				inv10 = line.rstrip("\n")
			elif inv11 in line:
				inv11 = line.rstrip("\n")
			elif inv12 in line:
				inv12 = line.rstrip("\n")
			elif inv13 in line: #new after 1597092311
				inv13 = line.rstrip("\n")
				break

	with open(foldername + "/" + str(index) + ".ivy", 'r') as read_obj:
		waiting = True
		for line in read_obj:
			if waiting:
				if "} #end easyTrace" in line:
					waiting = False
					continue
			elif dropped:
				inv13 += new_invariant
				print("found livelock: " + new_invariant + " to \033[0;37;45mDROPPED\033[0m [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv13 (DROPPED)\n")
				break
			elif (trav6 == "south") and (trav5 == "west") and (inv1 in line):
				inv1 += new_invariant
				print("found livelock: " + new_invariant + " to inv1 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv1\n")
				break
			elif (trav6 == "west") and (trav5 == "north") and (inv2 in line):
				inv2 += new_invariant
				print("found livelock: " + new_invariant + " to inv2 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv2\n")
				break
			elif (trav6 == "north") and (trav5 == "east") and (inv3 in line):
				inv3 += new_invariant
				print("found livelock: " + new_invariant + " to inv3 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv3\n")
				break
			elif (trav6 == "east") and (trav5 == "south") and (inv4 in line):
				inv4 += new_invariant
				print("found livelock: " + new_invariant + " to inv4 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv4\n")
				break
			elif (trav6 == "east") and (trav5 == "north") and (inv5 in line):
				inv5 += new_invariant
				print("found livelock: " + new_invariant + " to inv5 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv5\n")
				break
			elif (trav6 == "north") and (trav5 == "west") and (inv6 in line):
				inv6 += new_invariant
				print("found livelock: " + new_invariant + " to inv6 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv6\n")
				break
			elif (trav6 == "west") and (trav5 == "south") and (inv7 in line):
				inv7 += new_invariant
				print("found livelock: " + new_invariant + " to inv7 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv7\n")
				break
			elif (trav6 == "south") and (trav5 == "east") and (inv8 in line):
				inv8 += new_invariant
				print("found livelock: " + new_invariant + " to inv8 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv8\n")
				break
			elif (trav6 == "west") and (trav5 == "east") and (inv9 in line):
				inv9 += new_invariant
				print("found livelock: " + new_invariant + " to inv9 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv9\n")
				break
			elif (trav6 == "east") and (trav5 == "west") and (inv10 in line):
				inv10 += new_invariant
				print("found livelock: " + new_invariant + " to inv10 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv10\n")
				break
			elif (trav6 == "north") and (trav5 == "south") and (inv11 in line):
				inv11 += new_invariant
				print("found livelock: " + new_invariant + " to inv11 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv11\n")
				break
			elif (trav6 == "south") and (trav5 == "north") and (inv12 in line):
				inv12 += new_invariant
				print("found livelock: " + new_invariant + " to inv12 [" + str(index) + "]", end="")
				logfile.write("found livelock: " + new_invariant + " to inv12\n")
				break

	# play_beep()
	index += 1
	

	with open(foldername + "/" + str(index - 1) + ".ivy", 'r') as old:
		with open(foldername + "/" + str(index) + ".ivy", 'w') as new:
			for line in old:
				if "} #end easyTrace" in line:
					new.write(line)
					break
				else:
					new.write(line)
			for line in old:
				if new_invariant in line:
					print("\033[0;30;41m!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_\a\n")
					print("\033[0;30;41mINVARIANT ALREADY EXISTS. SOMETHING WENT WRONG. CHECK TRACES.\n")
					print("\033[0;30;41m!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_\a")
					print("\033[0;30;41m!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_!_\a\n\n\033[0m")
					exit(0)
			new.write("\n")
			new.write(inv1  + "\n")
			new.write(inv2  + "\n")
			new.write(inv3  + "\n")
			new.write(inv4  + "\n")
			new.write(inv5  + "\n")
			new.write(inv6  + "\n")
			new.write(inv7  + "\n")
			new.write(inv8  + "\n")
			new.write(inv9  + "\n")
			new.write(inv10 + "\n")
			new.write(inv11 + "\n")
			new.write(inv12 + "\n")
			if drop_tester:
				new.write(inv13 + "\n")
			new.write("\n# success. edited by python script in folder " + foldername)
	
	general_timer_duration = time.time() - general_timer_start
	print(" in %.2f seconds" % general_timer_duration, end = "")
	print(" (%.2f ivy)" % ivy_timer_duration)

print("That's all, folks!")

print("\n\n\a\033[0;32;47m####################################################################################################################################################################################################\033[0m")
for x in range(0, 30):
	print("\033[0;32;47m####################################################################################################################################################################################################\033[0m")
	time.sleep(0.1)
print("\n\n")