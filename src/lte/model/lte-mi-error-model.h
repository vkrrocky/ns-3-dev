/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 SIGNET LAB. Department of Information Engineering (DEI), University of Padua
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Original Authors: Marco Mezzavilla <mezzavil@dei.unipd.it>
 *                   Giovanni Tomasi <tomasigv@gmail.com>
 * Integration in LENA and extension done by: 
 *                            Marco Miozzo <marco.miozzo@cttc.es>
 */

#ifndef LTE_MI_ERROR_MODEL_H
#define LTE_MI_ERROR_MODEL_H


#include <list>
#include <vector>
#include <ns3/ptr.h>
#include <stdint.h>
#include <ns3/spectrum-value.h>




namespace ns3 {
  
  const uint16_t MI_MAP_QPSK_SIZE = 411;
  const uint16_t MI_MAP_16QAM_SIZE = 601;
  const uint16_t MI_MAP_64QAM_SIZE = 676;
  


/**
 * This class provides the BLER estimation based on mutual information metrics
 */
class LteMiErrorModel
{

public:

  LteMiErrorModel (void);

  ~LteMiErrorModel (void);

  /** 
   * \brief find the mmib (mean mutual information per bit) for different modulations of the specified TB
   * \param sinr the perceived sinrs in the whole bandwidth
   * \param map the actives RBs for the TB
   * \param cms the MCS of the TB
   * \return the mmib
   */
  static double Mib (SpectrumValue& sinr, std::vector<int> map, uint8_t mcs);
  /** 
   * \brief map the mmib (mean mutual information per bit) for different MCS
   * \param mmib mean mutual information per bit of a code-block
   * \param mcs the MCS
   * \param cbSize the size of the CB
   * \return the bler
   */
  static double MappingMiBler (double mib, uint8_t mcs, uint16_t cbSize);

  /** 
   * \brief run the error-model algorithm for the specified TB
   * \param modulation the modulations (qpsk, 16-qam, 64-qam)
   * \param code block-size and code-rate
   */  
  static double GetTbError (SpectrumValue& sinr, std::vector<int> map, uint16_t size, uint8_t mcs);


//private:



};


} // namespace ns3

#endif /* LTE_MI_ERROR_MODEL_H */
