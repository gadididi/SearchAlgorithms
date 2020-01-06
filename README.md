
## Prerequisites

1. [Install git](https://git-scm.com/download/) on your machine
2. [Sign up](http://www.github.com) to github

## Install

1. Clone the project on your machine:

    ```bash
    git clone https://github.com/ori294/SearchAlgorithms.git
    ```

2. Check the status of your project - you may be asked to provide credentials.

    ```bash
    git status
    ```

## Develop

1. Start with pulling the most recent updates to your local project. Do it everytime someone says he upload new changes:

    ```bash
    git pull origin master
    ```

2. Git works with a main branch called `master` and many sub branches which you can open. So, before you start making changes - create a local branch on your machine:

    ```bash
    git checkout -b <branch_name>
    ```

3. Check you are in working on your current branch and **not on `master`**. This command should print on which branch are you working in (make sure it is the *branch_name* you set). This command will also display which changes you've set.

    ```bash
    git status
    ```

4. When you feel ready, commit your changes to your local branch run:

    ```bash
    git checkout . ; git commit -m "add a short description for what you've done"
    ```

5. Now that you finished commiting your changes on your **local** branch, upload your branch with the changes to github.

    ```bash
    git push origin <branch_name>
    ```

6. Open new pull request
   1. Go to the project's [_branches_](https://github.com/ori294/SearchAlgorithms/branches) tab on github, and click **_New pull request_**
   2. Next click **_Creat pull request_**
   3. Now, if you feel ready to add your changes to the project, and if everything can be merged (none of us tried to change the same file at the same time) click **_Merge pull request_**

7. That's it! Now all you need to do is branch back to `master` and pull your edits and changes. Run these two commands one after another:

    ```bash
    git checkout master
    git pull origin master
    ```

* In some cases you will not be able to merge your changes - please refer to the next section: **Merging other people's changes**

You are now ready to start your new branch and run through all again (from 1 to 7).

### Merging other people's changes

It is possible some of us are working on the same files. If one pushed changes to `master`, after we started working on the files (in a seperate branch) - **github** will tell us we need to merge changes.

Merging changes is done as follows:

1. First, add any changes you have:

    ```bash
    git checkout . ; git commit -m "add a short description for what you've done"
    ```

2. Next, pull latest changes from master: `git pull origin master`
3. Rebase your local branch with `master`: `git rebase master`
4. That's it, now all we need to do is push our branch again to github. Github will detect it can merge our branch: `git push origin <branch_name>`
