APPNAME = "sw"

def options(opt):
	opt.load('compiler_cxx waf_unit_test')

def configure(cgf):
	cgf.load('compiler_cxx waf_unit_test')

def build(bld):
	assemble_executable(bld)
	test(bld)

def assemble_executable(bld):
	bld.program(
		cxxflags='-std=c++11',
		source='src/main.cc', 
		target=APPNAME,
		includes='src')

def test(bld):
	bld.program(
		features='test',
		cxxflags='-std=c++11',
		source='src/test.cc',
		target='utests',
		includes='src')

	from waflib.Tools import waf_unit_test
	bld.add_post_fun(waf_unit_test.summary)
	bld.add_post_fun(waf_unit_test.set_exit_code)
