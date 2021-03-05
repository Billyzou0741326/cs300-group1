# ChocAn Data Processing Software
![Github c++](https://img.shields.io/badge/c++-11-blue)


## Dev environment (command line)

To make a local clone of the repository: 

```
git clone git@github.com:Billyzou0741326/cs300-group1.git
cd cs300-group1
```

To make sure the local commits are up to date:

```
git pull origin main
```

Note that if the local commit history conflicts with the remote history, or has unsaved changes, `git pull` may fail.

Commit and push:

```
git add .
git commit -m <commit_message>
git push origin main
```


## Testing

Tests are written with the [googletest](https://github.com/google/googletest) framework.

To compile tests, run `make test`. Tests for each module are compiled separately and linked to the googletest framework.


## Compilation

To produce .o object files, run `make all` or simply `make`. 
