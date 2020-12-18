import os

path = "/mnt/c/users/lando/documents/github/routing_protocol/routing/time_tests"

with open(path + "/_time_analysis.txt", 'w') as write_obj:
	write_obj.write("Time Analysis:\n\n")
		for a in range(2,16):
			try:
				print("Getting time for the " + str(a) + "x" + str(a) + " network.")
				with open(path + "/" + str(a) + "x" + str(a) + "/_" + str(a) + "x" + str(a) + "_time.txt", "r") as read_obj:
					write.obj.write("Analysis for the " + str(a) + "x" + str(a) + " network: ")
					next(read_obj)
					write_obj.write(next(read_obj))

			except OSError:
				print("Error on " + str(a) + "x" + str(a) + "/")
				continue