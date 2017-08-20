#!/bin/python3

import signal
import logging

class GracefulKiller:
  __closables = []
  
  def __init__(self):
    signal.signal(signal.SIGINT, self.exit_gracefully)
    signal.signal(signal.SIGTERM, self.exit_gracefully)
    

  def add_closable(self,closable):
    self.__closables.append(predictor)

  def exit_gracefully(self,signum,frame):
    logging.debug('Llego señal de salida. Se va a cerrar el toxobot')    

    for closable in self.__closables:
      closable.close()