import os
import time

def check_pass(file_name):
	with open(file_name, 'r') as read_obj:
		for line in read_obj:
			if "PASS" in line:
				return True
	return False

def check_failed(file_name):
	with open(file_name, 'r') as read_obj:
		for line in read_obj:
			if "error:" in line:
				play_beep()
				for x in range(0,10):
					print("\033[0;30;41m   IVY RETURNED ERROR   \033[0m")
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
print("\033[0;30;42m Let's count some moves! \033[0m\n")

print("Your file options are as follows:")
os.system("ls *.ivy")
print("")

filename = input("\033[0;30;43mInput the name of the file without the extension: \033[0;37;44m")
if filename.endswith == ".ivy":
	filename = input("\033[0;30;41mWARNING! Try again without using .ivy: \033[0;37;44m")
ts = str(int(time.time()))
foldername = filename + "_tests_" + ts

os.system("mkdir " + foldername)
os.system("cp -i " + filename + ".ivy " + foldername + "/0.ivy")

logfile = open(foldername + "/log.txt", 'a')

print("\033[0m\nAll files opened correctly. Expect a large number of beeps once the script is finished.")
print("Look in this folder once completed: \033[0;36;40m" + foldername + "\033[0m")
print("The program will continue running without further interaction. Hold \033[0;30;43mCTRL+C\033[0m to exit.\n")

index = 0
finished = False

while not(finished) and index < 4000:
	
	general_timer_start = time.time()

	new_invariant = ""
	ivy_timer_start = time.time()
	os.system("ivy_check mc=true trace=true " + foldername + "/" + str(index) + ".ivy > " + foldername + "/" + str(index) + ".txt")
	ivy_timer_duration = time.time() - ivy_timer_start

	tempfilename = foldername + "/" + str(index) + ".txt"

	if check_failed(tempfilename):
		print("\033[0;30;41m  FAILURE: IVY ERROR!!! Big oops.  \033[0m")
		exit()
	elif check_pass(tempfilename):
		print("Testing has completed.")
		finished = True
		break
		
	index += 1
	new_invariant = "invariant flit.moveCounter <= " + str(index)
	
	with open(foldername + "/" + str(index - 1) + ".ivy", 'r') as old:
		with open(foldername + "/" + str(index) + ".ivy", 'w') as new:
			for line in old:
				if "#counter follows" in line:
					new.write(line)
					break
				else:
					new.write(line)
			new.write(new_invariant)
			new.write("\n# success. edited by python script in folder " + foldername)
	
	general_timer_duration = time.time() - general_timer_start 
	print("[" + str(index) + "] ", end = "")
	print("in %.2f seconds" % general_timer_duration, end = "")
	print(" (%.2f ivy)" % ivy_timer_duration)

print("That's all, folks!")

print("\n\n\a\033[0;37;42m####################################################################################################################################################################################################\033[0m")
for x in range(0, 30):
	print("\033[0;37;42m####################################################################################################################################################################################################\033[0m")
	time.sleep(0.1)
print("\n\n")