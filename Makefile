#############################################################################
# Makefile for building: CFK1
# Generated by qmake (2.01a) (Qt 4.8.1) on: ?? ??? 13 16:21:33 2013
# Project:  CFK2.pro
# Template: app
# Command: d:\qtsdk\desktop\qt\4.8.1\msvc2010\bin\qmake.exe -spec d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\win32-msvc2010 CONFIG+=declarative_debug -o Makefile CFK2.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = d:\qtsdk\desktop\qt\4.8.1\msvc2010\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: CFK2.pro  d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\win32-msvc2010\qmake.conf d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\qconfig.pri \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\modules\qt_webkit_version.pri \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt_functions.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt_config.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\exclusive_builds.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\default_pre.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\default_pre.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\debug.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\debug_and_release.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\default_post.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\default_post.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\declarative_debug.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\rtti.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\exceptions.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\stl.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\shared.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\embed_manifest_exe.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\embed_manifest_dll.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\warn_on.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\thread.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\moc.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\windows.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\resources.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\uic.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\yacc.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\lex.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\include_source_dir.prf \
		d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\lib\qtmaind.prl
	$(QMAKE) -spec d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\win32-msvc2010 CONFIG+=declarative_debug -o Makefile CFK2.pro
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\qconfig.pri:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\modules\qt_webkit_version.pri:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt_functions.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt_config.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\exclusive_builds.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\default_pre.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\default_pre.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\debug.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\debug_and_release.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\default_post.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\default_post.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\declarative_debug.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\rtti.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\exceptions.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\stl.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\shared.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\embed_manifest_exe.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\embed_manifest_dll.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\warn_on.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\qt.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\thread.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\moc.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\win32\windows.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\resources.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\uic.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\yacc.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\lex.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\features\include_source_dir.prf:
d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec d:\QtSDK\Desktop\Qt\4.8.1\msvc2010\mkspecs\win32-msvc2010 CONFIG+=declarative_debug -o Makefile CFK2.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
	-$(DEL_FILE) ".\CFK1.intermediate.manifest"
	-$(DEL_FILE) CFK1.exp
	-$(DEL_FILE) CFK1.ilk
	-$(DEL_FILE) vc*.pdb
	-$(DEL_FILE) vc*.idb
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) CFK1.pdb

check: first

debug-mocclean: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
