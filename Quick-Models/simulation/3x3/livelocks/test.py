import os

directory = "./ivyfiles"

for filename in os.listdir(directory):
    if filename.endswith(".ivy"):
        os.system("ivy_check trace=true ivyfiles/" + filename + " > ivyfiles/tests/" + filename.replace(".ivy",".txt"))
        # print("ivy_check trace=true " + filename + " > tests/" + filename.replace(".ivy",".txt"))