const std = @import("std");
const mem = std.mem;

const Name = enum {
    CP, MV, RM, MKDIR, CHECK_ENV, SET_ENV, UNSET_ENV, EXEC, PUTS, PROMPT,
    CONFIRM, IF, THEN, ELSE, END, COND, FOR, DO, LABEL, GOTO, DOWNLOAD, UPLOAD,
    UNKNOWN,
};

pub const Token = struct {
    name: Name,
    args: []const u8,

    pub fn init(name: []const u8, args: []const u8) Token {
        return Token{
            .name = Token.strToName(name),
            .args = args,
        };
    }

    pub fn strToName(name: []const u8) Name {
        const mappedName =
            if (mem.eql(u8, name, "if")) "if_"
            else if (mem.eql(u8, name, "else")) "else_"
            else if (mem.eql(u8, name, "for")) "for_"
            else name;
        const Case = enum {
            cp, mv, rm, mkdir, check_env, set_env, unset_env, exec, puts,
            prompt, confirm, if_, then, else_, end, cond, for_, do, label, goto,
            download, upload,
        };
        const case = std.meta.stringToEnum(Case, mappedName) orelse return Name.UNKNOWN;
        return switch (case) {
            .cp => Name.CP,
            .mv => Name.MV,
            .rm => Name.RM,
            .mkdir => Name.MKDIR,
            .check_env => Name.CHECK_ENV,
            .set_env => Name.SET_ENV,
            .unset_env => Name.UNSET_ENV,
            .exec => Name.EXEC,
            .puts => Name.PUTS,
            .prompt => Name.PROMPT,
            .confirm => Name.CONFIRM,
            .if_ => Name.IF,
            .then => Name.THEN,
            .else_ => Name.ELSE,
            .end => Name.END,
            .cond => Name.COND,
            .for_ => Name.FOR,
            .do => Name.DO,
            .label => Name.LABEL,
            .goto => Name.GOTO,
            .download => Name.DOWNLOAD,
            .upload => Name.UPLOAD,
        };
    }

    pub fn nameToStr(name: Name) []const u8 {
        return switch (name) {
            Name.CP => "cp",
            Name.MV => "mv",
            Name.RM => "rm",
            Name.MKDIR => "mkdir",
            Name.CHECK_ENV => "check_env",
            Name.SET_ENV => "set_env",
            Name.UNSET_ENV => "unset_env",
            Name.EXEC => "exec",
            Name.PUTS => "puts",
            Name.PROMPT => "prompt",
            Name.CONFIRM => "confirm",
            Name.IF => "if",
            Name.THEN => "then",
            Name.ELSE => "else",
            Name.END => "end",
            Name.COND => "cond",
            Name.FOR => "for",
            Name.DO => "do",
            Name.LABEL => "label",
            Name.GOTO => "goto",
            Name.DOWNLOAD => "download",
            Name.UPLOAD => "upload",
            Name.UNKNOWN => "unknown",
        };
    }

    pub fn getName(self: Token) Name {
        return self.name;
    }

    pub fn getArgs(self: Token) []const u8 {
        return self.args;
    }
};