#include "color_tracker_parameters.hpp"

using namespace cv::colortracker;
//构造函数
ColorTrackerParameters::ColorTrackerParameters()
{
	//parameters according to the paper
	padding = 1.0;         			   // extra area surrounding the target
	output_sigma_factor = 1.0 / 16;		   // spatial bandwidth(proportional to target)
	sigma = 0.2;         			   // gaussian kernel bandwidth
	lambda = 1e-2;					   // regularization(denoted "lambda" in the paper)
	learning_rate = 0.075;			   // learning rate for appearance model update scheme(denoted "gamma" in the paper)
	compression_learning_rate = 0.15;   // learning rate for the adaptive dimensionality reduction(denoted "mu" in the paper)
	non_compressed_features = vector<string>({ "gray" }); // features that are not compressed, a cell with strings(possible choices : 'gray', 'cn')
	compressed_features = vector<string>({ "cn" });       // features that are compressed, a cell with strings(possible choices : 'gray', 'cn')
	num_compressed_dim = 2;             // the dimensionality of the compressed features
	visualization = 1;
}
