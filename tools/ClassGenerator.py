
import sys
import argparse
import os

ARGUMENT_MINIMUM = 2
header_path = ""
src_path = ""

def initArgs() -> argparse.ArgumentParser:
    """


    """
    parser = argparse.ArgumentParser(prog="ClassGenerator", description="This script automates class generation for c++ programs. It is intended for those who don't use IDEs to automatically generate class files.")

    parser.add_argument('-cl', '--ClassName')
    parser.add_argument('-i', '--inheritance', help="foobar")
    parser.add_argument('-hp','--headerPath')
    parser.add_argument('-sp','--sourcePath')
    parser.add_argument('-a', '--alias')
    parser.add_argument('-an','--aliasName')
    parser.add_argument('-o', '--overwrite',   action="store_true")
    parser.add_argument('-c', '--constructor', action="store_true")
    parser.add_argument('-ip','--ignorePath',  action="store_true")
    parser.add_argument('-f','--functions',    nargs='+')
    parser.add_argument('-m','--members',      nargs='+')
    
    return parser


def writeHeader(args):

    if os.path.exists(f"{header_path}{args.ClassName}.h") and args.overwrite or not os.path.exists(f"{header_path}{args.ClassName}.h"):

        with open(f"{header_path}{args.ClassName}.h",'w') as file:

            if args.inheritance != None and len(args.inheritance) != 0:
                file.write(f"class {args.ClassName} : public {args.inheritance}" + "{\n\n")
            else:
                file.write(f"class {args.ClassName}" + "{\n\n")
            
            file.write(f"private:\n\n")

            for member in args.members:
                file.write(f"{member};\n")

            file.write(f"\npublic:\n\n")

            if(args.constructor):
                file.write(f"\n\t{args.ClassName}()" + "{\n\n\t}\n")

            writeFunctions(file,args,True)

            file.write("};")

def writeSource(args):

    if os.path.exists(f"{src_path}{args.ClassName}.cpp") and args.overwrite or not os.path.exists(f"{src_path}{args.ClassName}.cpp"):

        with open(f"{src_path}{args.ClassName}.cpp",'w') as file:
            
            file.write(f'#include "../{header_path}{args.ClassName}.h"\n\n')
            
            writeFunctions(file,args,False)


def writeFunctions(file,args,header):

    for function in args.functions:
        _type = function.split(" ")[0]
        _declaration = function.replace(_type,"",1)[1:]

        func = f"{_type} {args.ClassName}::{_declaration}" + "{\n\n}" + "\n\n" if not header else f"\t{_type} {_declaration};\n\n"

        file.write(func)
   

def checkPaths(args):
    global header_path
    global src_path

    header_path = 'headers' if args.headerPath == None or len(args.headerPath) <= 0 else args.headerPath
    src_path    = 'src'     if args.sourcePath == None or len(args.sourcePath) <= 0 else args.sourcePath

    if not args.ignorePath:
        if not os.path.isdir(header_path):
            os.mkdir(header_path)
        if not os.path.isdir(src_path):
            os.mkdir(src_path)

    header_path += '/'
    src_path    += '/'

def defineAlias(args):
    """
        @author:        Barnold8
        @description:   Defines an alias for a Linux user given their given alias path and possible custom alias name
    
    """
    aliasDefinition = args.alias
    script_path     = os.path.realpath(__file__)
    alias_name      = "ClassGen" if args.aliasName == None or len(args.aliasName) == 0 else args.aliasName

    if aliasDefinition != None and len(aliasDefinition) != 0:
        if os.path.exists(aliasDefinition):
            with open(aliasDefinition,"a") as file:
                file.write(f'\nalias {alias_name}="python ~/{script_path}"')
     

def main() -> int:

    parser = initArgs()

    if len(sys.argv) < ARGUMENT_MINIMUM:
        print(f"Script expects arguments, you entered {len(sys.argv)} arguments")
        return -1

    args = parser.parse_args() # grab arguments from user

    defineAlias(args)
    checkPaths(args)

    ## Generate class

    writeHeader(args)

    writeSource(args)

    ## Generate class


    return 0

main()

