import numpy as np
import pandas as pd
import random as rd
from random import randint
import matplotlib.pyplot as plt
n=34
item_number = np.arange(1,n+1)
weight = [x**4 for x in item_number]
value = weight
ts = sum(weight)
knapsack_threshold =  ts // 2  #Maximum weight that the bag of thief can hold
print('The list is as follows:')
print('Item No.   Weight   Value')
for i in range(item_number.shape[0]):
    print('{0}          {1}         {2}'.format(item_number[i], weight[i], value[i]))


solutions_per_pop = n
num_generations = 5000
pop_size = (solutions_per_pop, item_number.shape[0])
print('Population size = {}'.format(pop_size))
initial_population = np.random.randint(2, size = pop_size)

# 1 2 3 4 5 6 7 8 |9 10 11 12 13 14 15 16| 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
# 1 0 0 1 0 1 1 0 |0  1  1  0  1  0  0  1|  0  1  1  0  1  0  0  1  1  0  0  1  0  1  1  0
# 1 4 6 7 10 11 13 16 18 19 21 24 25 28 30 31
ar1 = [1,4,6,7,10,11,13,16,18,19,21,24,25,28,30,31]
ar2 = [1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0]
initial_population[0]=[0 for x in range(1,n%32+1)]+ar2
initial_population = initial_population.astype(int)

print('Initial population: {}'.format(initial_population))

def cal_fitness(weight, value, population, threshold):
    fitness = np.empty(population.shape[0])
    for i in range(population.shape[0]):
        S1 = np.sum(population[i] * value)
        S2 = np.sum(population[i] * weight)
        if S2 <= threshold:
            fitness[i] = S1
        else :
            fitness[i] = 0
    return fitness.astype(int)

def selection(fitness, num_parents, population):
    fitness = list(fitness)
    parents = np.empty((num_parents, population.shape[1]))
    for i in range(num_parents):
        max_fitness_idx = np.where(fitness == np.max(fitness))
        parents[i,:] = population[max_fitness_idx[0][0], :]
        fitness[max_fitness_idx[0][0]] = -999999
    return parents

def crossover(parents, num_offsprings):
    offsprings = np.empty((num_offsprings, parents.shape[1]))
    crossover_point = int(parents.shape[1]/2)
    crossover_rate = 0.8
    i=0
    while (parents.shape[0] < num_offsprings):
        parent1_index = i%parents.shape[0]
        parent2_index = (i+1)%parents.shape[0]
        x = rd.random()
        if x > crossover_rate:
            continue
        parent1_index = i%parents.shape[0]
        parent2_index = (i+1)%parents.shape[0]
        offsprings[i,0:crossover_point] = parents[parent1_index,0:crossover_point]
        offsprings[i,crossover_point:] = parents[parent2_index,crossover_point:]
        i=+1
    return offsprings
def mutation(offsprings):
    mutants = np.empty((offsprings.shape))
    mutation_rate = 0.4
    for i in range(mutants.shape[0]):
        random_value = rd.random()
        mutants[i,:] = offsprings[i,:]
        if random_value > mutation_rate:
            continue
        int_random_value = randint(0,offsprings.shape[1]-1)
        if mutants[i,int_random_value] == 0 :
            mutants[i,int_random_value] = 1
        else :
            mutants[i,int_random_value] = 0
    return mutants

def optimize(weight, value, population, pop_size, num_generations, threshold):
    parameters, fitness_history = [], []
    num_parents = int(pop_size[0]/2)
    num_offsprings = pop_size[0] - num_parents
    for i in range(num_generations):
        fitness = cal_fitness(weight, value, population, threshold)
        fitness_history.append(fitness)
        parents = selection(fitness, num_parents, population)
        offsprings = crossover(parents, num_offsprings)
        mutants = mutation(offsprings)
        population[0:parents.shape[0], :] = parents
        population[parents.shape[0]:, :] = mutants

    print('Last generation: \n{}\n'.format(population))
    fitness_last_gen = cal_fitness(weight, value, population, threshold)
    print('Fitness of the last generation: \n{}\n'.format(fitness_last_gen))
    max_fitness = np.where(fitness_last_gen == np.max(fitness_last_gen))
    parameters.append(population[max_fitness[0][0],:])
    return parameters, fitness_history

parameters, fitness_history = optimize(weight, value, initial_population, pop_size, num_generations, knapsack_threshold)
print('The optimized parameters for the given inputs are: \n{}'.format(parameters))
selected_items = item_number * parameters
ans = []
print('\nSelected items that will maximize the knapsack without breaking it:')
s = 0
for i in range(selected_items.shape[1]):
  if selected_items[0][i] != 0:
     print('{}\t'.format(selected_items[0][i]))
     ans.append(selected_items[0][i])
     s+=weight[selected_items[0][i]-1]

print("RESULT:\n")
print(s)
print(knapsack_threshold)
print(ts - 2 * s)

btst = [0] * n
for i in ans:
    btst[i-1]=1
# for i in btst


