; benchmark generated from python API
(set-info :status unknown)
(declare-fun __r_E_00.tally () Int)
(declare-fun r_E_00.tally () Int)
(declare-fun __flit_to_watch () Int)
(declare-fun flit_to_watch () Int)
(declare-fun r_E_00.id () Int)
(declare-fun r_W_10.tally () Int)
(declare-fun r_N_10.tally () Int)
(declare-fun r_S_11.tally () Int)
(declare-fun __ts0_a () Bool)
(declare-fun __r_E_00.has_flit () Bool)
(declare-fun r_E_00.has_flit () Bool)
(declare-fun |r_W_10.assigned:1| () Bool)
(declare-fun |r_W_10.assigned:2| () Bool)
(declare-fun |r_W_10.assigned:0| () Bool)
(declare-fun r_S_11.has_flit () Bool)
(declare-fun r_W_10.has_flit () Bool)
(assert
 (let (($x134 (= r_E_00.id __flit_to_watch)))
 (let (($x173 (<= r_W_10.tally 5)))
 (let (($x233 (<= r_N_10.tally 5)))
 (let (($x452 (<= __r_E_00.tally 5)))
 (let (($x187 (<= r_S_11.tally 5)))
 (let (($x66 (and (and |r_W_10.assigned:2| (and |r_W_10.assigned:1| true)) (and true (and false true)))))
 (let (($x124 (and (= |r_W_10.assigned:2| true) (= |r_W_10.assigned:1| false) (= |r_W_10.assigned:0| true))))
 (let (($x63 (and (and |r_W_10.assigned:2| (and |r_W_10.assigned:1| true)) (and false (and false true)))))
 (let (($x88 (and (= |r_W_10.assigned:2| false) (= |r_W_10.assigned:1| false) (= |r_W_10.assigned:0| false))))
 (let (($x23 (not (and r_W_10.has_flit (or $x88 $x63) r_S_11.has_flit (or $x124 $x66)))))
 (and $x23 $x187 $x452 $x233 $x173 __r_E_00.has_flit $x134 (or (not __ts0_a) (not (<= r_E_00.tally 5))) (or (not __ts0_a) (= r_E_00.has_flit __r_E_00.has_flit)) (or (not __ts0_a) (= flit_to_watch __flit_to_watch)) (or (not __ts0_a) (= r_E_00.tally (+ __r_E_00.tally 1))) (or __ts0_a or) (= __ts0_a (< __r_E_00.tally 5))))))))))))))
(assert
 (and (not or)))
(check-sat)
