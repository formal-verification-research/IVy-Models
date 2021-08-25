zones = "abcdefghijklmnopqrstuvwxy"

inv = "invariant "

import os

print(len(zones))

with open('inv.txt','w') as ofile:
    for y in range(len(zones)):
        for z in range(y+1,len(zones)):
            print(zones[y] + " with " + zones[z])
            inv = inv + "(zone(" + zones[y] + ").ok & zone(" + zones[z] + ").ok) -> ("
            for i in range(1,18):
                inv = inv + "zone(" + zones[y] + ").c" + str(i).zfill(2) + " ~= zone(" + zones[z] + ").c" + str(i).zfill(2) + " | "
            inv = inv + "zone(" + zones[y] + ").c18 ~= zone(" + zones[z] + ").c18) "
            # print(inv)
            ofile.write(inv + "\n")
            inv = "invariant "
    
    ofile.write("\n\n")

    for y in range(len(zones)):
        inv = inv + "zone(" + zones[y] + ").ok -> ("
        for i in range(1,18):
            inv = inv + "zone(" + zones[y] + ").c" + str(i).zfill(2) + " | "
        inv = inv + "zone(" + zones[y] + ").c18) "
        # print(inv)
        ofile.write(inv + "\n")
        inv = "invariant "
        
    ofile.write("\n\n")
    
    for i in range(1,19):
        inv = inv + "("
        
        for y in range(len(zones)-1):
            inv = inv + "zone(" + zones[y] + ").ok & "
        inv = inv + "zone(r).ok) -> ("
        
        for y in range(len(zones)-1):
            inv = inv + "zone(" + zones[y] + ").c" + str(i).zfill(2) + " | "
        inv = inv + "zone(r).c18)"
        
        ofile.write(inv + "\n")
        inv = "invariant "