#ifndef GLOBAL_MODEL_H
#define GLOBAL_MODEL_H
#include "Facilities.h"
#include "Invoices.h"
#include "Staffs.h"
#include "InvoiceDetail.h"

extern FacilitiesModel *facilityModel = new FacilitiesModel();
extern InvoiceDetailModel *invoiceDetailModel = new InvoiceDetailModel();
extern InvoiceModel *invoiceModel = new InvoiceModel();
extern StaffsModel *StaffModel = new StaffsModel();

#endif