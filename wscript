APPNAME = "sw" 
VERSION = "1.0.0"

srcdir = "src"
blddir = "build"

def set_options(opt):
	opt.tool_options("compiler_cxx")

def configure(conf):
	conf.check_tool("compiler_cxx")

def build(bld):
       bld(features="cxx cprogram",
    source="src/main.cc",
    cxxflags=["-O3","-Wall","-std=c++11"],
    target="sw",
    includes="src")

def shutdown(ctx):
	pass


