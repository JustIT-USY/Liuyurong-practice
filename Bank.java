package cn.itcast.Second;

public class Bank {
	
	static String bankName;
	private String name;
	private String password;
	private double balance;
	private double turnover;

    //静态方法，打印出银行欢迎语句
	static void welcome(){
		System.out.println("欢迎来到"+bankName+"------------");
	}
    //构造方法 开户
	public Bank (String name,String password ,double turnover){
		//将变量赋值给成员变量
		this.name=name;
		this.password=password;
		this.turnover=turnover;
	    this.balance = turnover - 10;
	    System.out.println(name+"开户成功，账户余额"+balance) ;
	}
	//存款
	public void deposit (double turnover) {
	balance = balance + turnover;
	System.out.println (name+"您好， 您的账户已存入"+turnover+"元,"+ "当前余額"+balance+"元");
	}
	//取款
	public void withdrawal(String password, double turnover){
	if (this.password != password) {
	System.out.println ("您输入的密码错误! ") ;
	return;
	}
	//判断余额是否充足
	if (balance - turnover > 0) {
	balance = balance - turnover;
	System.out.println(name+"您好，您的余额己取出"+turnover+"元,"+"当前余額"+balance+"元") ;
    }
	else 
	System.out.println("対不起，账户余额不足! ") ;
	}
	//静态方法
	static void welcomeNext(){
	System.out.println("请携带好随身财物，欢迎下次光临"+bankName+"-----------");


 
}
	}
