<div align=center>
	<h1>
		<i>Pipex</i>
	</h1>
	<img src=https://github.com/AnaVolkmann/42_project_badges/blob/main/badges/pipexe.png alt=fract-ol_badge/>
	<p align=center>
        <p align="center">
	<b><i>Reproduction of shell pipes</i></b><br>
  
---

<h2>
		Final score
	</h2>
	<img src= https://github.com/AnaVolkmann/AnaVolkmann/blob/main/score_pipex.png alt=fractol_grade/>

---

</div>

<h1> About <img src=https://github.com/AnaVolkmann/AnaVolkmann/blob/main/mario_pipeplant(2).gif alt=pipex_pipe/>
</h2>

Pipex is a C project that simulates the behavior of the shell when piping the output of one command to the input of another using the | operator. The project involves using system calls like fork(), pipe(), dup2(), and execve() to create a pipeline between two processes, enabling them to communicate by passing data from one command to another, just as you would in a Unix-like shell.

````
# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
 
# pipe() sends the output of the first execve() as input to the second execve()
# fork() runs two processes (i.e. two commands) in one single program
# dup2() swaps our files with stdin and stdout
 ````

