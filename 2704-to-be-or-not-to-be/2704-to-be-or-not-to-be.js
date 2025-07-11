/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {

    return {
        toBe: function(go){
            if (val === go) {
                return true;
            } else {
                throw new Error("Not Equal");
            }
        },
        notToBe: function (go){
            if (val !== go) {
                return true;
            } else {
               throw new Error("Equal");
            }
        }
    }
};
