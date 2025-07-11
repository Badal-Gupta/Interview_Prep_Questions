/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(arr, fn, init) {
    if(arr.length===0){
        return init;
    }else{
        let a = init;
        arr.forEach((sum)=>{
            a = fn(a,sum);
        });
        return a;
    }
};