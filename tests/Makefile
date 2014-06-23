
###############  Changeable  Parameters  ##############

include ../Makefile.common

OUTPUT_DIR = ../bld

ifeq ($(MAIN_EXE_NAME),)
    MAIN_EXE_NAME     =   langutilstest
endif

###############  DO NOT MODIFY BELOW THIS   ##############

CUTILS_HOME = ../../cutils

UNITTEST_PP_DIR     = ./UnitTest++
TEST_SOURCE_FOLDERS = .
INCLUDE_FOLDERS     = ../src $(CUTILS_HOME)/src
LIBRARY_FOLDERS     = $(CUTILS_HOME)/bld
TEST_SOURCES        := $(foreach dir,$(TEST_SOURCE_FOLDERS),$(wildcard $(dir)/*.cpp))
UNITTEST_PP_SOURCES := $(wildcard $(UNITTEST_PP_DIR)/*.cpp) $(wildcard $(UNITTEST_PP_DIR)/Posix/*.cpp)

ALL_SOURCES_IN_INCLUDE_FOLDERS  := $(shell find $(INCLUDE_FOLDERS) -name \*.[ch] )
SOURCES_WITH_TEST_TAGS          = $(shell grep -l "@test" $(ALL_SOURCES_IN_INCLUDE_FOLDERS) )

TEST_OBJS           = $(foreach obj, $(patsubst %.cpp,%.o,$(TEST_SOURCES)), $(OUTPUT_DIR)/tests/$(obj))
UNITTEST_PP_OBJS 		= $(patsubst %.cpp,%.o,$(UNITTEST_PP_SOURCES)) 
TEST_OUTPUT         = $(OUTPUT_DIR)/$(MAIN_EXE_NAME)
ARCHIVES            = # $(UNITTEST_PP_DIR)/libUnitTest++.a

LIBS                =  # -lcutils


###################     Begin Targets       ######################

# Implicit rule to build .o into the build directory from .cpp
$(OUTPUT_DIR)/tests/%.o : %.cpp
	@echo Building tests/$<  \-\>  $@ 
	@$(GPP) -I$(UNITTEST_PP_DIR) -I. -c $(CFLAGS) $< -o $@

$(UNITTEST_PP_DIR)/%.o : %.cpp
	@echo Building tests/$<  \-\>  $@ 
	@$(GPP) -I$(UNITTEST_PP_DIR) -I. -c $(CFLAGS) $< -o $@

.PHONY: clean cleanall distclean tests

tests: base $(TEST_OBJS) $(UNITTEST_PP_OBJS) 
	@echo Building Test with Static Libraries...
	@$(GPP) $(CFLAGS) $(TEST_OBJS) $(UNITTEST_PP_OBJS) $(OUTPUT_DIR)/liblangutils.a $(ARCHIVES) -o $(TEST_OUTPUT) $(LIBS)
	@echo 
	@echo Running Tests...
	@echo 
	$(TEST_OUTPUT)

base:
	@echo Building test output directories...
	@mkdir -p "$(OUTPUT_DIR)/tests" "$(OUTPUT_DIR)/UnitTest++" "$(OUTPUT_DIR)/UnitTest++/Posix"

clean:
	@echo Tests Objs: $(TEST_OBJS)
	@rm -f $(TEST_OBJS)

cleanall: clean
	@rm -f "$(TEST_OUTPUT)"

distclean: cleanall
	@rm -f Makefile

dep:
	makedepend -Y -p"$(OUTPUT_DIR)/" $(INCLUDE_FLAGS)  -- $(TEST_SOURCES)
# DO NOT DELETE

../bld/./asttests.o: ../src/langutils.h ../src/lufwddefs.h
../bld/./asttests.o: ../../cutils/src/cutils.h ../../cutils/src/cufwddefs.h
../bld/./asttests.o: ../../cutils/src/cuallocator.h
../bld/./asttests.o: ../../cutils/src/cuprototype.h
../bld/./asttests.o: ../../cutils/src/cuobject.h ../../cutils/src/cuerror.h
../bld/./asttests.o: ../../cutils/src/cucollection.h
../bld/./asttests.o: ../../cutils/src/culinkedlist.h
../bld/./asttests.o: ../../cutils/src/culist.h ../../cutils/src/cuarray.h
../bld/./asttests.o: ../../cutils/src/cumap.h ../../cutils/src/cuset.h
../bld/./asttests.o: ../../cutils/src/custring.h ../../cutils/src/custreams.h
../bld/./asttests.o: ../../cutils/src/cuiterator.h
../bld/./asttests.o: ../../cutils/src/cuconcurrency.h ../src/lutokenizer.h
../bld/./asttests.o: ../src/luast.h ../src/lutypes.h
../bld/./typetests.o: ../src/langutils.h ../src/lufwddefs.h
../bld/./typetests.o: ../../cutils/src/cutils.h ../../cutils/src/cufwddefs.h
../bld/./typetests.o: ../../cutils/src/cuallocator.h
../bld/./typetests.o: ../../cutils/src/cuprototype.h
../bld/./typetests.o: ../../cutils/src/cuobject.h ../../cutils/src/cuerror.h
../bld/./typetests.o: ../../cutils/src/cucollection.h
../bld/./typetests.o: ../../cutils/src/culinkedlist.h
../bld/./typetests.o: ../../cutils/src/culist.h ../../cutils/src/cuarray.h
../bld/./typetests.o: ../../cutils/src/cumap.h ../../cutils/src/cuset.h
../bld/./typetests.o: ../../cutils/src/custring.h
../bld/./typetests.o: ../../cutils/src/custreams.h
../bld/./typetests.o: ../../cutils/src/cuiterator.h
../bld/./typetests.o: ../../cutils/src/cuconcurrency.h ../src/lutokenizer.h
../bld/./typetests.o: ../src/luast.h ../src/lutypes.h
