
###############  Changeable  Parameters  ##############

include ../Makefile.common

OUTPUT_DIR = ../bld

###############  DO NOT MODIFY BELOW THIS   ##############

SHARED_LIB_NAME         = lib$(PRODUCT_NAME).so.$(VERSION)
STATIC_LIB_NAME         = lib$(PRODUCT_NAME).a.$(VERSION)

ifeq ($(BUILD_MODE), debug)
    SHARED_LIB_NAME     = lib$(PRODUCT_NAME)_debug.so.$(VERSION)
    STATIC_LIB_NAME     = lib$(PRODUCT_NAME)_debug.a.$(VERSION)
endif

SHARED_LIB_OUTPUT       =   "$(OUTPUT_DIR)/$(SHARED_LIB_NAME)"
STATIC_LIB_OUTPUT       =   "$(OUTPUT_DIR)/$(STATIC_LIB_NAME)"

CUTILS_HOME = ../../cutils

SOURCE_FOLDERS  =   . 
LIBRARY_FOLDERS     = $(CUTILS_HOME)/bld
INCLUDE_FOLDERS :=  $(foreach dir,$(SOURCE_FOLDERS),$(dir)) $(CUTILS_HOME)/src
LANGUTILS_SOURCES   := $(foreach dir,$(SOURCE_FOLDERS),$(wildcard $(dir)/*.c))
LANGUTILS_OBJS      = $(foreach obj, $(patsubst %.c,%.o,$(LANGUTILS_SOURCES)), $(OUTPUT_DIR)/src/$(obj))
LIBS                = -lcutils

###################     Begin Targets       ######################

# Implicit rule to build .o into the build directory from .c
$(OUTPUT_DIR)/src/%.o : %.c
	@echo Building src/$<  \-\>  $@ 
	@$(GCC)  -std=c99 -c $(CFLAGS) $< -o $@

all: base static shared
	@echo LIB_INSTALL_DIR     = $(LIB_INSTALL_DIR)
	@echo INCLUDE_INSTALL_DIR = $(INCLUDE_INSTALL_DIR)

shared: base $(LANGUTILS_OBJS)
	@echo Creating Shared Library ...
	@$(GCC) -shared $(CFLAGS) $(LANGUTILS_OBJS) -o "$(SHARED_LIB_OUTPUT)" $(LIBS)
	@rm -f "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).so"
	@ln -s "$(SHARED_LIB_NAME)" "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).so"

static: base $(LANGUTILS_OBJS)
	@echo Creating Static Library ...
	@ar rcs "$(STATIC_LIB_OUTPUT)" $(LANGUTILS_OBJS)
	@rm -f "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).a"
	@ln -s "$(STATIC_LIB_NAME)" "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).a"

install: shared static
	@echo "Copying library files..."
	@mkdir -p "$(LIB_INSTALL_DIR)"
	@mkdir -p "$(INCLUDE_INSTALL_DIR)/lunarprobe"
	@cp -f "$(SHARED_LIB_OUTPUT)" "$(LIB_INSTALL_DIR)"
	@cp -f "$(STATIC_LIB_OUTPUT)" "$(LIB_INSTALL_DIR)"
	@rm -f "$(LIB_INSTALL_DIR)/lib$(PRODUCT_NAME).so"
	@ln -s "$(LIB_INSTALL_DIR)/$(SHARED_LIB_NAME)" "$(LIB_INSTALL_DIR)/lib$(PRODUCT_NAME).so"
	@echo "Copying header files..."
	@cp -f *.h $(INCLUDE_INSTALL_DIR)/lunarprobe

base:
	@echo Building output directories...
	@mkdir -p "$(OUTPUT_DIR)/src"
	@cd $(OUTPUT_DIR)/src ; mkdir -p $(SOURCE_FOLDERS)

.PHONY: clean cleanall distclean
clean:
	@rm -f $(LANGUTILS_OBJS) $(ENTRY_OBJS)

cleanall: clean
	@rm -f "$(SHARED_LIB_OUTPUT)" "$(STATIC_LIB_OUTPUT)"
	@rm -f "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).so"
	@rm -f "$(OUTPUT_DIR)/lib$(PRODUCT_NAME).a"

distclean: cleanall
	@rm -f Makefile

dep:
	makedepend -Y -p"$(OUTPUT_DIR)/" $(INCLUDE_FLAGS) -- $(LANGUTILS_SOURCES)

# DO NOT DELETE

../bld/./luast.o: langutils.h lufwddefs.h ../../cutils/src/cutils.h
../bld/./luast.o: ../../cutils/src/cufwddefs.h ../../cutils/src/cuallocator.h
../bld/./luast.o: ../../cutils/src/cuprototype.h ../../cutils/src/cuobject.h
../bld/./luast.o: ../../cutils/src/cuerror.h ../../cutils/src/cucollection.h
../bld/./luast.o: ../../cutils/src/culinkedlist.h ../../cutils/src/culist.h
../bld/./luast.o: ../../cutils/src/cuarray.h ../../cutils/src/cumap.h
../bld/./luast.o: ../../cutils/src/cuset.h ../../cutils/src/custring.h
../bld/./luast.o: ../../cutils/src/custreams.h ../../cutils/src/cuiterator.h
../bld/./luast.o: ../../cutils/src/cuconcurrency.h lutokenizer.h luast.h
../bld/./luast.o: lutypes.h
../bld/./lutokenizer.o: langutils.h lufwddefs.h ../../cutils/src/cutils.h
../bld/./lutokenizer.o: ../../cutils/src/cufwddefs.h
../bld/./lutokenizer.o: ../../cutils/src/cuallocator.h
../bld/./lutokenizer.o: ../../cutils/src/cuprototype.h
../bld/./lutokenizer.o: ../../cutils/src/cuobject.h
../bld/./lutokenizer.o: ../../cutils/src/cuerror.h
../bld/./lutokenizer.o: ../../cutils/src/cucollection.h
../bld/./lutokenizer.o: ../../cutils/src/culinkedlist.h
../bld/./lutokenizer.o: ../../cutils/src/culist.h ../../cutils/src/cuarray.h
../bld/./lutokenizer.o: ../../cutils/src/cumap.h ../../cutils/src/cuset.h
../bld/./lutokenizer.o: ../../cutils/src/custring.h
../bld/./lutokenizer.o: ../../cutils/src/custreams.h
../bld/./lutokenizer.o: ../../cutils/src/cuiterator.h
../bld/./lutokenizer.o: ../../cutils/src/cuconcurrency.h lutokenizer.h
../bld/./lutokenizer.o: luast.h lutypes.h
../bld/./lutypes.o: langutils.h lufwddefs.h ../../cutils/src/cutils.h
../bld/./lutypes.o: ../../cutils/src/cufwddefs.h
../bld/./lutypes.o: ../../cutils/src/cuallocator.h
../bld/./lutypes.o: ../../cutils/src/cuprototype.h
../bld/./lutypes.o: ../../cutils/src/cuobject.h ../../cutils/src/cuerror.h
../bld/./lutypes.o: ../../cutils/src/cucollection.h
../bld/./lutypes.o: ../../cutils/src/culinkedlist.h ../../cutils/src/culist.h
../bld/./lutypes.o: ../../cutils/src/cuarray.h ../../cutils/src/cumap.h
../bld/./lutypes.o: ../../cutils/src/cuset.h ../../cutils/src/custring.h
../bld/./lutypes.o: ../../cutils/src/custreams.h
../bld/./lutypes.o: ../../cutils/src/cuiterator.h
../bld/./lutypes.o: ../../cutils/src/cuconcurrency.h lutokenizer.h luast.h
../bld/./lutypes.o: lutypes.h
