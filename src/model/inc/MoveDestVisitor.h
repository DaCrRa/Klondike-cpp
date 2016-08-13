#ifndef SRC_INC_MOVEDESTVISITOR_H_
#define SRC_INC_MOVDESTVISITOR_H_

class TableauPile;
class Foundation;

class MoveDestVisitor {
public:
    virtual void visit(TableauPile* stock) = 0;
    virtual void visit(Foundation* stock) = 0;
    virtual ~MoveDestVisitor() {}
};

#endif /* SRC_INC_MOVEDESTVISITOR_H_ */
