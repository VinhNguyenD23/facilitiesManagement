#ifndef INVOICEDETAILMODEL_H
#define INVOICEDETAILMODEL_H

class InvoiceDetailModel
{
private:
    /* data */
public:
    InvoiceDetailModel(/* args */);
    template <typename T>
    void linkData(T *data);
    ~InvoiceDetailModel();
};

#endif
