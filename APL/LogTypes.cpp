// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
//  
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
// 

#include "LogTypes.h"
#include "Util.h"

#include <sstream>

namespace apl {

int LogTypes::FilterLevelToMask(FilterLevel aFilter)
{
	//since FilterLevel is a power of 2 (single bit), subtracting 1 will
	//set all the bits below the set bit.
	//set the filter bit and all the bits below it
	return aFilter | (aFilter-1);
}

int LogTypes::GetFilterMask(char c)
{
	bool success = true;
	switch(c) {
			case('a'): return MASK_ALL_LEVELS;
			case('d'): return LEV_DEBUG;
			case('c'): return LEV_COMM;
			case('p'): return LEV_INTERPRET;
			case('i'): return LEV_INFO;
			case('w'): return LEV_WARNING;
			case('e'): return LEV_ERROR;
			case('v'): return LEV_EVENT;
			case('n'): return 0;
			default:
				return -1;
	}
}

int LogTypes::GetFilterMask(const std::string& arg)
{
	std::string copy(arg);
	toLowerCase(copy);
	int ret = 0;
	for(size_t i=0; i<copy.size(); ++i) ret |= GetFilterMask(copy[i]);
	return ret;
}

std::string LogTypes::GetLevelString( FilterLevel aLevel )
{
	switch(aLevel) {
		case(LEV_DEBUG): return "DEBUG";
		case(LEV_COMM): return "COMM";
		case(LEV_INTERPRET): return "INTERPRET";
		case(LEV_INFO): return "INFO";
		case(LEV_WARNING):return "WARNING";
		case(LEV_ERROR): return "ERROR";
		case(LEV_EVENT): return "EVENT";
		default: return "UNKNOWN";
	}		
}

std::string LogTypes::GetFilterString(int aLevel)
{
	std::ostringstream oss;

	oss << "[";

	if( (aLevel & LEV_DEBUG) ) oss << "d";
	if( (aLevel & LEV_COMM) )	 oss << "c";
	if( (aLevel & LEV_INTERPRET) ) oss << "p";
	if( (aLevel & LEV_INFO) ) oss << "i";
	if( (aLevel & LEV_WARNING) ) oss << "w";
	if( (aLevel & LEV_ERROR) ) oss << "e";
	if( (aLevel & LEV_EVENT) ) oss << "v";

	oss << "]";

	return oss.str();
}

}
