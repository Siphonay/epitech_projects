#!/bin/bash
## skip-synthesis.sh for automakefile in /home/sam/Rendu/Piscine_S/automakefile
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Mon Jun 27 09:14:09 2016 Alexis Viguié
## Last update Tue Jun 28 14:17:55 2016 Alexis Viguié
##

grep -e "\(.*\ \)\{8\}$1" | tr -s ' ' | cut -d ' ' -f 3,9- | sed -e "s/ /\t/"
