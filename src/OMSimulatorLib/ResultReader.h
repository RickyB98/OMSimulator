/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#ifndef _OMS_RESULTREADER_H_
#define _OMS_RESULTREADER_H_

#include <string>
#include <vector>

namespace oms
{
  class ResultReader
  {
  public:
    struct Series
    {
      unsigned int length;
      double* time;
      double* value;
    };

    ResultReader(const char* filename);
    virtual ~ResultReader();

    static ResultReader* newReader(const char* filename);

    virtual Series* getSeries(const char* var) = 0;
    const std::vector<std::string>& getAllSignals() const {return signals;}

    static void deleteSeries(Series** series);
    static bool compareSeries(Series* seriesA, Series* seriesB, double relTol, double absTol);

  private:
    // Stop the compiler generating methods for copying the object
    ResultReader(ResultReader const& copy);            // Not Implemented
    ResultReader& operator=(ResultReader const& copy); // Not Implemented

  protected:
    std::vector<std::string> signals;
  };
}

#endif
