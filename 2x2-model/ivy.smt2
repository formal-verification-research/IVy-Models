; benchmark generated from python API
(set-info :status unknown)
(declare-fun __r_E_00.tally () (_ BitVec 16))
(declare-fun r_E_00.tally () (_ BitVec 16))
(declare-fun flit_to_watch () (_ BitVec 16))
(declare-fun r_E_00.id () (_ BitVec 16))
(declare-fun r_N_10.tally () (_ BitVec 16))
(declare-fun r_S_11.tally () (_ BitVec 16))
(declare-fun r_W_10.tally () (_ BitVec 16))
(declare-fun r_E_00.has_flit () Bool)
(declare-fun |r_W_10.assigned:0| () Bool)
(declare-fun |r_W_10.assigned:1| () Bool)
(declare-fun |r_W_10.assigned:2| () Bool)
(declare-fun r_S_11.has_flit () Bool)
(declare-fun r_W_10.has_flit () Bool)
(assert
 (let (($x28 (= r_E_00.id flit_to_watch)))
 (let (($x556 (and |r_W_10.assigned:2| (and |r_W_10.assigned:1| (and |r_W_10.assigned:0| true)))))
 (let (($x35 (and (= |r_W_10.assigned:2| true) (= |r_W_10.assigned:1| true) (= |r_W_10.assigned:0| false))))
 (let (($x257 (and (= |r_W_10.assigned:2| false) (= |r_W_10.assigned:1| false) (= |r_W_10.assigned:0| true))))
 (let (($x232 (and r_W_10.has_flit (or $x257 (and $x556 (and false (and false (and true true))))) r_S_11.has_flit (or $x35 (and $x556 (and true (and true (and false true))))))))
 (and (not $x232) (bvule r_S_11.tally (_ bv5 16)) (bvule __r_E_00.tally (_ bv5 16)) (bvule r_N_10.tally (_ bv5 16)) (bvule r_W_10.tally (_ bv5 16)) (not (bvugt r_S_11.tally (_ bv5 16))) (not (bvugt r_N_10.tally (_ bv5 16))) (not (= flit_to_watch (_ bv0 16))) r_E_00.has_flit $x28 (not (bvule r_E_00.tally (_ bv5 16))) (= r_E_00.tally (bvadd __r_E_00.tally (_ bv1 16))))))))))
(assert
 (and (not or)))
(check-sat)
