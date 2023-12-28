# building with batch files through cmd 

- Open cmd ( no need admin )
- Write `shell` into the cmd // it will open enviroment
- Then if you wan to build just write `build`
- And if you want to directly compile and run , just type `devenv` and locate build dir to open main.exe

:: For now keep it as main.exe , maybe later change it to something else.

# changing batch files to your liking

## build settings 
- hop into `build` for  




## shell settings

- shell.bat has list of directories you can change

```batch
set path=src;%path% 
set include=lib\include;%include%
set lib=lib\library;%library%

:: after = , put your own path
```

## editor settings

- no