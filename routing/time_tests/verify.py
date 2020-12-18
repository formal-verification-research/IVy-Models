import os

import calendar;
import time;
ts = calendar.timegm(time.gmtime())

path = "/mnt/c/users/lando/documents/github/routing_protocol/routing/time_tests/" + str(ts)

os.system("mkdir " + str(ts))

try:
	os.chdir(path)
	print("Your directory is " + str(ts))
	os.system("cp -r ../base .")
except OSError:
	print("Can't change the Current Working Directory")
	os._exit(0)

lowerBound = int(input("What is your min NoC dimension? "))
upperBound = int(input("What is your max NoC dimension? ")) + 1

# From verify.py, set up folders

for a in range(lowerBound,upperBound):
	place = str(a) + "x" + str(a)
	# os.system("rm -r " + place)
	# print("Working on " + place + ".")
	os.chdir(path)
	os.system("mkdir " + place)
	os.system("cp -r base/* " + place)

	dummy_file = path + "/" + place + "/main.cpp" + '.bak'
	original = path + "/" + place + "/main.cpp"

	with open(original, 'r') as read_obj, open(dummy_file, 'w') as write_obj:
		write_obj.write("#define MAX_X " + str(a-1) + "\n#define MAX_Y "  + str(a-1) + "\n\n")
		for line in read_obj:
			write_obj.write(line)
	os.remove(original)
	os.rename(dummy_file, original)

	dummy_file = path + "/" + place + "/route.cpp" + '.bak'
	original = path + "/" + place + "/route.cpp"

	with open(original, 'r') as read_obj, open(dummy_file, 'w') as write_obj:
		write_obj.write("#define MAX_X " + str(a-1) + "\n#define MAX_Y "  + str(a-1) + "\n\n")
		for line in read_obj:
			write_obj.write(line)
	os.remove(original)
	os.rename(dummy_file, original)

	print("------------------------------------------------------------------")
	try:
		# Change the current working Directory    
		os.chdir(path + "/" + str(a) + "x" + str(a) + "/")
		print("Testing the " + str(a) + "x" + str(a) + " network.")
	except OSError:
		print("Can't change the Current Working Directory to /" + str(a) + "x" + str(a) + "/")
		continue
	
	os.system("g++ *.cpp")
	os.system("./a.out")



# From analysis.py, do the paste the numbers in one

with open(path + "/_time_analysis.txt", 'w') as write_obj:
	write_obj.write("Time Analysis:\n\n")
	for a in range(lowerBound,upperBound):
		try:
			print("Getting time for the " + str(a) + "x" + str(a) + " network.")
			with open(path + "/" + str(a) + "x" + str(a) + "/_" + str(a) + "x" + str(a) + "_time.txt", "r") as read_obj:
				write_obj.write("Analysis for the " + str(a) + "x" + str(a) + " network: ")
				next(read_obj)
				write_obj.write(next(read_obj))
		except OSError:
			print("Error on " + str(a) + "x" + str(a) + "/")
			continue


print("Done. Thank you.")