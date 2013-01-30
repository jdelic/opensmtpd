/*	$OpenBSD: parser.h,v 1.24 2013/01/26 09:37:23 gilles Exp $	*/

/*
 * Copyright (c) 2006 Pierre-Yves Ritschard <pyr@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

enum actions {
	NONE,
	SHUTDOWN,
	MONITOR,
	LOG_VERBOSE,
	LOG_BRIEF,
	SCHEDULE,
	SHOW_QUEUE,
	SHOW_STATS,
	SHOW_SIZES,
	SHOW_ENVELOPE,
	SHOW_MESSAGE,
	PAUSE_MDA,
	PAUSE_MTA,
	PAUSE_SMTP,
	REMOVE,
	RESUME_MDA,
	RESUME_MTA,
	RESUME_SMTP,
	UPDATE_TABLE,
	LOG_TRACE_IMSG,
	LOG_TRACE_IO,
	LOG_TRACE_SMTP,
	LOG_TRACE_MFA,
	LOG_TRACE_MTA,
	LOG_TRACE_BOUNCE,
	LOG_TRACE_SCHEDULER,
	LOG_TRACE_LOOKUP,
	LOG_TRACE_STAT,
	LOG_TRACE_RULES,
	LOG_TRACE_IMSG_SIZE,
	LOG_TRACE_ALL,
	LOG_UNTRACE_IMSG,
	LOG_UNTRACE_IO,
	LOG_UNTRACE_SMTP,
	LOG_UNTRACE_MFA,
	LOG_UNTRACE_MTA,
	LOG_UNTRACE_BOUNCE,
	LOG_UNTRACE_SCHEDULER,
	LOG_UNTRACE_LOOKUP,
	LOG_UNTRACE_STAT,
	LOG_UNTRACE_RULES,
	LOG_UNTRACE_IMSG_SIZE,
	LOG_UNTRACE_ALL,
	LOG_PROFILE_IMSG,
	LOG_PROFILE_QUEUE,
	LOG_UNPROFILE_IMSG,
	LOG_UNPROFILE_QUEUE,
};

struct ctl_id {
	objid_t		 id;
	char		 name[MAX_NAME_SIZE];
};

struct parse_result {
	struct ctl_id	id;
	enum actions	action;
	const char     *data;
};

struct parse_result	*parse(int, char *[]);
