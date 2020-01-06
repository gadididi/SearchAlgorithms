# SearchAlgorithms
Description will be added later on.
# Interpreter-Flight-Simulator-language
Interpreter for a flight simulator coding language, made with CPP. 

Prerequisites
Install git on your machine
Sign up to github
Install
Clone the project on your machine:

git clone https://github.com/ori294/Interpreter-Flight-Simulator-language.git
Check the status of your project - you may be asked to provide credentials.

git status
Develop
Start with pulling the most recent updates to your local project. Do it everytime someone says he upload new changes:

git pull origin master
Git works with a main branch called master and many sub branches which you can open. So, before you start making changes - create a local branch on your machine:

git checkout -b <branch_name>
Check you are in working on your current branch and not on master. This command should print on which branch are you working in (make sure it is the branch_name you set). This command will also display which changes you've set.

git status
When you feel ready, commit your changes to your local branch run:

git checkout . ; git commit -m "add a short description for what you've done"
Now that you finished commiting your changes on your local branch, upload your branch with the changes to github.

git push origin <branch_name>
Open new pull request

Go to the project's branches tab on github, and click New pull request
Next click Creat pull request
Now, if you feel ready to add your changes to the project, and if everything can be merged (none of us tried to change the same file at the same time) click Merge pull request
That's it! Now all you need to do is branch back to master and pull your edits and changes. Run these two commands one after another:

git checkout master
git pull origin master
In some cases you will not be able to merge your changes - please refer to the next section: Merging other people's changes
You are now ready to start your new branch and run through all again (from 1 to 7).

Merging other people's changes
It is possible some of us are working on the same files. If one pushed changes to master, after we started working on the files (in a seperate branch) - github will tell us we need to merge changes.

Merging changes is done as follows:

First, add any changes you have:

git checkout . ; git commit -m "add a short description for what you've done"
Next, pull latest changes from master: git pull origin master

Rebase your local branch with master: git rebase master

That's it, now all we need to do is push our branch again to github. Github will detect it can merge our branch: git push origin <branch_name>
