# ChocAn Data Processing Software
![Github c++](https://img.shields.io/badge/c++-11-blue)


This software allows service providers to record information about services rendered to ChocAn members and bill ChocAn accordingly. It also allows ChocAn operators and managers to view and edit lists of members and providers in the ChocAn network and to generate a selection of business reports. This section of the document discusses users and stakeholders, and use cases. A user is someone who interacts with the finished product. A stakeholder is anyone who will be affected by the software. For more information, refer to the requirements and design document.


## Compilation

If [make](https://www.gnu.org/software/make/) is installed on the system, simply run `make` to build the executable.


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
