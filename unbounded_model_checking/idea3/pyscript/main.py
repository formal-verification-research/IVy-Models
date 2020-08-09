import os
import time

def check_pass(file_name):
    with open(file_name, 'r') as read_obj:
        for line in read_obj:
            if "PASS" in line:
                return True
    return False

print("Let's do this thing.")
time.sleep(0.5)

filename = input("Input the name of the file without the extension: ")
ts = str(int(time.time()))
foldername = filename + "_tests_" + ts

os.system("mkdir " + foldername)
os.system("cp -i " + filename + ".ivy " + foldername + "/0.ivy")

logfile = open(foldername + "/log.txt", 'a')

index = 0
finished = False

while not(finished) and index < 200:
	
	zn6 = 'x'
	zn5 = 'x'
	zn4 = 'x'
	zn3 = 'x'
	zn2 = 'x'
	zn1 = 'x'
	zn0 = 'x'
	trav6 = 'x'
	trav5 = 'x'
	trav4 = 'x'
	trav3 = 'x'
	trav2 = 'x'
	trav1 = 'x'
	trav0 = 'x'
	
	os.system("ivy_check mc=true trace=true " + foldername + "/" + str(index) + ".ivy > " + foldername + "/" + str(index) + ".txt")
	tempfilename = foldername + "/" + str(index) + ".txt"
	if check_pass(tempfilename):
		print("Testing has completed.")
		if index == 0:
			print("NO LIVELOCK FOUND! HIP HIP HOORAY!")
		finished = True
		break
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
				# finished = True
	
	new_invariant = " | (flit.zn6 = " + zn6 + " & flit.zn5 = " + zn5 + " & flit.zn4 = " + zn4 + " & flit.zn3 = " + zn3 + " & flit.zn2 = " + zn2 + " & flit.zn1 = " + zn1 + ")"

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
				break

	with open(foldername + "/" + str(index) + ".ivy", 'r') as read_obj:
		waiting = True
		for line in read_obj:
			if waiting:
				if "} #end easyTrace" in line:
					waiting = False
					continue
			elif (trav6 == "south") and (trav5 == "west") and (inv1 in line):
				inv1 += new_invariant
				print("Added conditions: " + new_invariant + " to inv1")
				logfile.write("Added conditions: " + new_invariant + " to inv1\n")
				break
			elif (trav6 == "west") and (trav5 == "north") and (inv2 in line):
				inv2 += new_invariant
				print("Added conditions: " + new_invariant + " to inv2")
				logfile.write("Added conditions: " + new_invariant + " to inv2\n")
				break
			elif (trav6 == "north") and (trav5 == "east") and (inv3 in line):
				inv3 += new_invariant
				print("Added conditions: " + new_invariant + " to inv3")
				logfile.write("Added conditions: " + new_invariant + " to inv3\n")
				break
			elif (trav6 == "east") and (trav5 == "south") and (inv4 in line):
				inv4 += new_invariant
				print("Added conditions: " + new_invariant + " to inv4")
				logfile.write("Added conditions: " + new_invariant + " to inv4\n")
				break
			elif (trav6 == "east") and (trav5 == "north") and (inv5 in line):
				inv5 += new_invariant
				print("Added conditions: " + new_invariant + " to inv5")
				logfile.write("Added conditions: " + new_invariant + " to inv5\n")
				break
			elif (trav6 == "north") and (trav5 == "west") and (inv6 in line):
				inv6 += new_invariant
				print("Added conditions: " + new_invariant + " to inv6")
				logfile.write("Added conditions: " + new_invariant + " to inv6\n")
				break
			elif (trav6 == "west") and (trav5 == "south") and (inv7 in line):
				inv7 += new_invariant
				print("Added conditions: " + new_invariant + " to inv7")
				logfile.write("Added conditions: " + new_invariant + " to inv7\n")
				break
			elif (trav6 == "south") and (trav5 == "east") and (inv8 in line):
				inv8 += new_invariant
				print("Added conditions: " + new_invariant + " to inv8")
				logfile.write("Added conditions: " + new_invariant + " to inv8\n")
				break
			elif (trav6 == "west") and (trav5 == "east") and (inv9 in line):
				inv9 += new_invariant
				print("Added conditions: " + new_invariant + " to inv9")
				logfile.write("Added conditions: " + new_invariant + " to inv9\n")
				break
			elif (trav6 == "east") and (trav5 == "west") and (inv10 in line):
				inv10 += new_invariant
				print("Added conditions: " + new_invariant + " to inv10")
				logfile.write("Added conditions: " + new_invariant + " to inv10\n")
				break
			elif (trav6 == "north") and (trav5 == "south") and (inv11 in line):
				inv11 += new_invariant
				print("Added conditions: " + new_invariant + " to inv11")
				logfile.write("Added conditions: " + new_invariant + " to inv11\n")
				break
			elif (trav6 == "south") and (trav5 == "north") and (inv12 in line):
				inv12 += new_invariant
				print("Added conditions: " + new_invariant + " to inv12")
				logfile.write("Added conditions: " + new_invariant + " to inv12\n")
				break

	index += 1

	with open(foldername + "/" + str(index - 1) + ".ivy", 'r') as old:
		with open(foldername + "/" + str(index) + ".ivy", 'w') as new:
			for line in old:
				if "} #end easyTrace" in line:
					new.write(line)
					break
				else:
					new.write(line)
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
			new.write("\n#success. edited by python script")

print("That's all, folks!")