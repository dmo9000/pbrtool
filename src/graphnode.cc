#include <iostream>
#include "graphnode.h"

void GraphNode::Identify()
{

//	std::cerr << "GraphNode[" << node_seq_id << ":" << is_valid << ":" << x << ":" << y << "] nspeaking \n";
}

GraphNode::GraphNode(int seq_id, double spawnx, double spawny)
{
	node_seq_id = seq_id;
	x = spawnx;
	y = spawny;
	is_valid = 1;
	std::cerr << "GraphNode(" << node_seq_id << ":" << x << ":" << y << ") constructor\n";
}

GraphNode::~GraphNode() 
{
	std::cerr << "GraphNode(" << node_seq_id << ") destructor\n";
	is_valid = 0;
}

void GraphNode::Set_X(int nx)
{
	x = nx;
}

void GraphNode::Set_Y(int ny)
{
	y = ny;
}

int GraphNode::Get_X() 
{
	return x;
}

int GraphNode::Get_Y() 
{
	return y;
}

int GraphNode::Get_SX() 
{
	return sx;
}

int GraphNode::Get_SY() 
{
	return sy;
}

int GraphNode::AddInput() 
{
	GraphConnector *new_connector = NULL;
	new_connector = new GraphConnector;
	inputs.push_back(new_connector);
  Recalculate_Size();
	return -1;
}

int GraphNode::AddOutput() 
{
	GraphConnector *new_connector = NULL;
	new_connector = new GraphConnector;
	outputs.push_back(new_connector);
  Recalculate_Size();
	return -1;
}

int GraphNode::NumberOfInputs()
{
	return inputs.size(); 
}

int GraphNode::NumberOfOutputs()
{
	return outputs.size();
}

int GraphNode::Recalculate_Size()
{
	int max_inputs = 0;
	int min_inputs = 0;
	/* make sure enough vertical size for all inputs / outputs */
	max_inputs = (inputs.size() > outputs.size () ? inputs.size() : outputs.size());
	min_inputs = (max_inputs > 3 ? max_inputs : 3);
 	if (sy != (((min_inputs-1) * 16) + 32)) {
			sy = (((min_inputs-1) * 16) + 32);
			std::cerr << "graphnode(" << node_seq_id << "): new size x=" << sx << ", y=" << sy << "\n"; 	
			}
}