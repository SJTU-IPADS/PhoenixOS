import sys
import glob

'''
argv[1] - module name
'''
kArgvIndex_module = 1

args = sys.argv

# add all local source files
sources = glob.glob(f"./{args[kArgvIndex_module]}/**/*.c", recursive=True)     \
        + glob.glob(f"./{args[kArgvIndex_module]}/**/*.cpp", recursive=True)   \
        + glob.glob(f"./{args[kArgvIndex_module]}/**/*.cc", recursive=True)

for i in sources:
    if "__template__" in i or "__TEMPLATE__" in i:
        continue
    print(i)
