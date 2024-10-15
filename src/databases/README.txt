Facilities:
[id:string(10)],[name:string],[unit:string],[quantity:unsigned long]
Staff:
[id:string],[lastName:string],[firstName:string],[gender:bool]
Invoice:
[id:string(20)],[date:Date{Object}],[owner:string],[type:bool]
InvoiceDetail:
[id:long],[parentId:string(20)],[nameFacility:string],[quantity:unsigned long],[price:unsigned long],[VAT:double]

relationship:
Staff < Invoice
Invoice - InvoiceDetail
Facilities > InvoiceDetail

Explain:
< : 1 - n
> : n - 1
- : 1 - 1