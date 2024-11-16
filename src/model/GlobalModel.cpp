#include "GlobalModel.h"

FacilitiesModel *facilityModel = new FacilitiesModel();
InvoiceDetailModel *invoiceDetailModel = new InvoiceDetailModel();
InvoiceModel *invoiceModel = new InvoiceModel();
StaffsModel *staffModel = new StaffsModel();
void initialModel()
{
    facilityModel = new FacilitiesModel();
    invoiceDetailModel = new InvoiceDetailModel();
    invoiceModel = new InvoiceModel();
    staffModel = new StaffsModel();
}
