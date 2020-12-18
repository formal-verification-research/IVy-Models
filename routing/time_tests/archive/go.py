import os

path = "/mnt/c/users/lando/documents/github/routing_protocol/routing/time_tests"

for a in range(2,5):
	print("------------------------------------------------------------------")
	try:
		# Change the current working Directory    
		os.chdir(path + "/" + str(a) + "x" + str(a) + "/")
		print("Testing the " + str(a) + "x" + str(a) + " network.")
	except OSError:
		print("Can't change the Current Working Directory to /" + str(a) + "x" + str(a) + "/")
		continue
	
	os.system("rm *.txt")
	os.system("rm livelocktrace/*")
	os.system("g++ *.cpp")
	os.system("./a.out")

os.system("python3 analysis.py")