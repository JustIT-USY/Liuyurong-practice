

(function(){
    //1.调用选项卡
    tab();

    //2.动态创建元素
    autoCreateImg();

    //3.瀑布流布局
    setTImeout(function () {
        waterFull("dom_pull","box");
    },200);

    //4.窗口的滚动
    window.onscroll=function () {
        //4.1 瀑布流加载新图片条件
        if(checkWIllLoadImag()){
            autoCreateImg();

            waterFull("dom_pull","box");
        }
        //4.2判断是否吸顶
        var scrollTop=scroll().top;
        if(scrollTop>=150){
           $('top_nav').style.display="block";
           $('elevator').style.display="block";
        }else{
            $('top_nav').style.display="none";
            $('elevator').style.display="none";
        }

        //4.4滚回顶部
        $('elevator').onclick=function () {
            buffer(document.documentElement,{scrollTop:0},null);
        }
    };

    //5.监听点击按钮
    $("login").onclick=function () {
        $("mask").style.display="none";
    };
    $("close.btn").onclick=function () {
        $("mask").style.display="block";
    };

    //6.广告轮播
    bannerAutoPlay();
})(window);

function autoCreateImg() {
    //1.1数据
    var json=[],str,text,pic,htmlStr;
    //1.2遍历
    for(var i=0; i<30;i++){
        //1.2.0获取父标签的文本
       str=$("dom_pull").innerHTML;
        //1.2.1取出图片的地址和文字
       text=json[i].txt;
       pic=json[i].pic;

       //1.2.2创建子标签
       htmlStr="  <div class=\"box\">\n" +
            " <div class=\"pic\">\n" +
            " <img src="+pic+" alt=\"\">\n" +
            " <div class=\"cover\"></div>\n" +
            " </div>\n" +
            " <p>"+ txt +"</p>\n" +
            " <div class=\"btn_box\">\n" +
            " <a href=\"\" class=\"collect\">采集</a>\n" +
            " <a href=\"\" class=\"like\">\n" +
            " <span class=\"heart\"></span>\n" +
            " </a>\n" +
            " </div>\n" +
            " </div>"

        //1.2.3拼接
        str+=htmlStr;
        $("dom_pull").innerHTML=str;

        //1.2.4绑定事件
          var wrapBox=$("dom_pull").getElementsByClassName("box");
          var wrapPic=$("dom_pull").getElementsByClassName("pic");
          for(var j=0;j<wrapBox.length;j++){
             wrapBox[j].onmouseover=function () {
                 this.childNodes[2].style.display="block";
             };
              wrapBox[j].onmouseout=function () {
                  this.childNodes[2].style.display="none";
              };
              wrappic[j].onmouseover=function () {
                  this.childNodes[1].style.display="block";
              };
              wrappic[j].onmouseout=function () {
                  this.childNodes[1].style.display="none";
              };
          }

    }
}

function bannerAutoPlay() {
    //1.获取所有li标签
    var lis=$("slider_banner").getElementsByTagName("li");
    var index=0;
    //2.开始定时器
    setInterval(function () {
        //2.1改变透明度
        for(var i=0;i<lis.length;i++){
            var singerLi=lis[i];
            buffer(singerLi,{opacity:0},null);
        }
        buffer(lis[index],{opacity:1},null);
        //2.2索引++
        index++;
        if(index===lis.length){
            index=0;
        }
    },3000);
}

function tab() {
    //1.获取需要的标签
    var allLis=$("tab_header").getElementsByTagName("li");
    var doms=$("tab_content").getElementsByClassName("dom");

    //console.log(allLis,doms);

    //2.遍历监听
    for(var i=0;i<allLis.length;i++){
        var li=allLis[i];
        (function (i) {
         li.onmouseover=function () {
             //1.清除样式
             allLis[lastOne].className="";
             doms[lastOne].style.display="none";
             //2.设置选中
             this.className="current";
             doms[i].style.display="block";
             //3.赋值
             lastOne = i;
         }
        })(i);
    }
}

function $(id) {
    return typeof id === "string"?document.getElementById(id):  null
}

