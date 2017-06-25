(function ($) {
    "use strict";
    $(document).ready(function () {
        /*Skillbar*/
        $(".skill-bar").each(function () {
            var percent = $(this).data('percent');
            if (typeof $.fn.appear === 'function') {
                $(this).appear(function () {
                    $(this).find('.progress-bar').css({width: percent});
                }, {
                    accX: 0,
                    accY: 0,
                    one: true
                });
            } else {
                $(this).find('.progress-bar').css({width: percent});
            }
        });
        /*Stats*/
        // $('.stat-count').each(function() {
        // if (typeof $.fn.appear === 'function') {
        // $(this).appear(function() {
        // statcount($(this));
        // }, {
        // accX: 0,
        // accY: 0,
        // one: true
        // });
        // } else {
        // statcount($(this));
        // }
        // });
        /*PieChart*/
        if (typeof $.fn.appear === 'function') {
            $('.dexp-pie-chart').each(function () {
                var $char = $(this);
                $char.appear(function () {
                    $char.dexpPieChart();
                    $char.unbind('appear');
                }, {
                    accX: 0,
                    accY: 0,
                    one: true
                });
            });
        } else {
            $('.dexp-pie-chart').dexpPieChart();
        }
    });
    $.fn.dexpPieChart = function () {
        return this.each(function () {
            var $this = $(this),
                    percent = $this.data('percent'),
                    title = $this.data('title'),
                    start = 0;
            if (title !== null && title !== "") {
                $this.append('<div class="ppc-progress"><div class="ppc-progress-fill"></div></div><div class="ppc-percents"><div class="pcc-percents-wrapper"><span>%</span><div class="pcc-title"></div></div></div>');
                $this.find('.ppc-percents .pcc-title').html(title);
            }else{
               $this.append('<div class="ppc-progress"><div class="ppc-progress-fill"></div></div><div class="ppc-percents"><div class="pcc-percents-wrapper"><span>%</span></div></div>'); 
            }
            var i = setInterval(function () {
                if (start <= percent) {
                    var deg = parseInt(start) * 3.6;
                    if (start > 50) {
                        $this.addClass('gt-50');
                    }
                    $this.find('.ppc-progress-fill').css('transform', 'rotate(' + deg + 'deg)');
                    $this.find('.ppc-percents span').html(start + '%');
                    start++;
                } else {
                    clearInterval(i);
                }
            }, 20);
        });
    };


}(jQuery));