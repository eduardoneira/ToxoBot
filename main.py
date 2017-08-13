#!/bin/python3

from os import *

if __name__ == '__main__':

  fd_stdin, fd_stdout = pipe()
  
  print("Starting ToxoBot")

  pid = fork()

  if pid == 0:
    close(fd_stdout)
    dup2(fd_stdin,0)
    execl("./pipe_in.sh","./pipe_in.sh")
    print("Execl failed")
    exit() 

  print("TOXOBOT: pid stdin process: %d" % pid)

  pid = fork()

  if pid == 0:
    close(fd_stdin)
    dup2(fd_stdout,1)
    execl("./pipe_out.sh","./pipe_out.sh")
    print("Execl failed")
    exit() 

  print("TOXOBOT: pid stdout process: %d" % pid)

  pid, status = wait()
  print("Process %d ended with status %d" % (pid,status))
  pid, status = wait()
  print("Process %d ended with status %d" % (pid,status))

  print("Childs have stopped. Exiting")

  close(fd_stdin)
  close(fd_stdout)

