#ifndef GLOBAL_MODEL_H
#define GLOBAL_MODEL_H
#include "Facilities.h"
#include "Invoices.h"
#include "Staffs.h"
#include "InvoiceDetail.h"

extern FacilitiesModel *facilityModel;
extern InvoiceDetailModel *invoiceDetailModel;
extern InvoiceModel *invoiceModel;
extern StaffsModel *staffModel;

void initialModel();

#endif
