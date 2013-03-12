import networkx as nx
import traceback,sys


graph = nx.graph()

def createGraph(file_name):
	print 'reading file', file
	graph = nx.read_gml(file)
	

def getBuffers(graph):
	#this should return a list of (str,int,str) tuples
	return eval(graph.graph['buffer_list'])

def getInputMap(graph):
	#this should return a list of (str,int,str) tuples
	return eval(graph.graph['input_list'])

def getOutputMap(graph):
	#this should return a list of (str,int,str) tuples
	return eval(graph.graph['output_list'])

def getNodeList(graph):
	#returns list of (name, 