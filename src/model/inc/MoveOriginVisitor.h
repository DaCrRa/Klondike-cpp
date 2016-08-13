#ifndef SRC_INC_MOVEORIGINVISITOR_H_
#define SRC_INC_MOVEORIGINVISITOR_H_

class Stock;
class TableauPile;
class Foundation;

class MoveOriginVisitor {
public:
    virtual void visit(Stock* stock) = 0;
    virtual void visit(TableauPile* stock) = 0;
    virtual void visit(Foundation* stock) = 0;
    virtual ~MoveOriginVisitor() {}
};

#endif /* SRC_INC_MOVEORIGINVISITOR_H_ */
