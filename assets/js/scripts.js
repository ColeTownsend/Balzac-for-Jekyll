$(document).ready(function() {
  $('a.menu').click(function() {
    $('.site-header nav').slideToggle(100);
    return false;
  });

  $(window).resize(function(){
    var w = $(window).width();
    var menu = $('.site-header nav');
    if(w > 680 && menu.is(':hidden')) {
      menu.removeAttr('style');
    }
  });


  $('article.post iframe').wrap('<div class="video-container" />');

});

$(document).ready(function() {
    var vpH = ($(window).height())*.6667;
    
    $('.overlay').css("height", vpH);
    $('.featured-image').css("height", vpH);

    $(window).resize(function(){
    var vpH = ($(window).height())*.6667;
    
    $('.overlay').css("height", vpH);
    $('.featured-image').css("height", vpH);
});
});


$(function(){
  $('<img>').attr('src',function(){
      var imgUrl = $('div.featured-image').css('background-image');
      imgUrl = imgUrl .substring(4, imgUrl .length-1);
      return imgUrl;
  }).load(function(){
    $('img.loading').fadeOut(500);
    $('div.overlay').fadeTo("slow", 0.6);
  });
});

$(function(){
    $('.post-list li').each(function(i){
        var t = $(this);
        setTimeout(function(){ t.addClass('slider'); }, (i+1) * 330);
    });
});
