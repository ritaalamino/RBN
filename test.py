#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import PyBoolNet
import numpy as np


#create_variables(primes, {"C":"A"})

nodes = 3

primes = FEX.read_primes("example01.primes")
matrix = np.random.randint(2,size=(nodes,nodes))
update = “synchronous"
primes2stg(primes,update,matrix)



if __name__=="__main__":

	# reading bnet files

	bnet = """
	v1,	!v1
	v2,	1
	v3,	v2 & (!v1 | v3)
	"""

	primes = PyBoolNet.FileExchange.bnet2primes(bnet)

	# finding nodes

	const = PyBoolNet.PrimeImplicants.find_constants(primes)
	print(const)

	# modifying networks

	PyBoolNet.PrimeImplicants.create_variables(primes, {"v4": "v4 | v2"})
	PyBoolNet.PrimeImplicants.create_variables(primes, {"v5": lambda v1,v2,v3: v1+v2+v3==1})

	print(PyBoolNet.FileExchange.primes2bnet(primes))

	# reading from the repository

	primes = PyBoolNet.Repository.get_primes("remy_tumorigenesis")
	print(PyBoolNet.FileExchange.primes2bnet(primes))




































# end of file
