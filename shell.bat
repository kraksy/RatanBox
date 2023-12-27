@echo
call "D:\apps\VS\VC\Auxiliary\Build\vcvarsall.bat" x64
set path=src;%path%
set include=lib\include;%include%
set lib=lib\library;%library%