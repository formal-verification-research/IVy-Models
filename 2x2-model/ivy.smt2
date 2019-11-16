; benchmark generated from python API
(set-info :status unknown)
(declare-fun __r_E_01.tally () Int)
(declare-fun r_E_01.tally () Int)
(declare-fun r_E_01.id () Int)
(declare-fun flit_to_watch () Int)
(declare-fun r_E_01.has_flit () Bool)
(assert
 (let (($x94 (and (= r_E_01.tally __r_E_01.tally) (not (< r_E_01.tally 0)) (not (< __r_E_01.tally 0)))))
 (let (($x78 (= r_E_01.id flit_to_watch)))
 (and r_E_01.has_flit $x78 (not (and r_E_01.has_flit $x78)) $x94 (not (< flit_to_watch 0)) (not (< r_E_01.id 0)) (not (< r_E_01.tally 0)) (not (< __r_E_01.tally 0))))))
(assert
 (and (not or)))
(check-sat)
