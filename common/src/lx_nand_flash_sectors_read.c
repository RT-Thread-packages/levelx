/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** LevelX Component                                                      */ 
/**                                                                       */
/**   NAND Flash                                                          */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define LX_SOURCE_CODE


/* Disable ThreadX error checking.  */

#ifndef LX_DISABLE_ERROR_CHECKING
#define LX_DISABLE_ERROR_CHECKING
#endif


/* Include necessary system files.  */

#include "lx_api.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _lx_nand_flash_sectors_read                         PORTABLE C      */ 
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Xiuwen Cai, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */ 
/*                                                                        */ 
/*    This function reads multiple logical sectors from NAND flash.       */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    nand_flash                            NAND flash instance           */ 
/*    logical_sector                        Logical sector number         */ 
/*    buffer                                Pointer to buffer to read into*/ 
/*                                            (the size is number of      */ 
/*                                             bytes in a page)           */ 
/*    sector_count                          Number of sector to read      */
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    return status                                                       */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    _lx_nand_flash_sector_read            Read a sector                 */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    Application Code                                                    */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Xiuwen Cai               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
UINT  _lx_nand_flash_sectors_read(LX_NAND_FLASH *nand_flash, ULONG logical_sector, VOID *buffer, ULONG sector_count)
{

UINT status = LX_SUCCESS;
UINT i;


    /* Loop to read all the sectors.  */
    for (i = 0; i < sector_count; i++)
    {

        /* Read one sector.  */
        status = _lx_nand_flash_sector_read(nand_flash, logical_sector + i, ((UCHAR*)buffer) + i * nand_flash -> lx_nand_flash_bytes_per_page);

        /* Check return status.  */
        if (status)
        {

            /* Error, break the loop.  */
            break;
        }
    }

    /* Return status.  */
    return(status);
}

