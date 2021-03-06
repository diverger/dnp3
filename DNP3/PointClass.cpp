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
#include "PointClass.h"

namespace apl { namespace dnp {

PointClass IntToPointClass(int aClass) {
	switch(aClass)
	{
		case(1): 
			return PC_CLASS_1;
		case(2): 
			return PC_CLASS_2;
		case(3): 
			return PC_CLASS_3;
		default: 
			return PC_CLASS_0;
	}
}

}}

