#ifndef _OPENCV_color_tracker_parameters_HPP_
#define _OPENCV_color_tracker_parameters_HPP_ 

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <fstream>

#ifdef __cplusplus
namespace cv { namespace colortracker {
		using namespace std;
		class ColorTrackerParameters
		{
		public:
            //extra area surrounding the target
            double padding;
            //spatial bandwidth(proportional to target)
            double output_sigma_factor;
            //gaussian kernel bandwidth
            double sigma;
            //regularization(denoted "lambda" in the paper)
            double lambda;
            //learning rate for appearance model update scheme(denoted "gamma" in the paper)
            double learning_rate;
            //learning rate for the adaptive dimensionality reduction(denoted "mu" in the paper)
            double compression_learning_rate;
            //features that are not compressed, a cell with strings(possible choices : 'gray', 'cn')
            vector<string> non_compressed_features;
            //features that are compressed, a cell with strings(possible choices : 'gray', 'cn')
            vector<string> compressed_features;
            //the dimensionality of the compressed features
            int num_compressed_dim;
            //visualization
			int visualization;
			string video_path;
			cv::Point init_pos;
			cv::Size wsize;
            //构造函数
			ColorTrackerParameters();
		};

	}
}
#endif
#endif
